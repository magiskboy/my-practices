import numpy as np

def sigmoid(z):
    return 1 / (1 + np.exp(-z))

def make_node(type_node, next_node, **kwargs):
    def input_node():
        while True:
            payload, is_forward = yield
            X, y = payload['X'], payload['y']
            if next_node:
                data = {'X': X, 'y': y}
                next_node.send((data, True))
            yield 0

    def linear_node():
        w = np.random.randn(*kwargs['shape'])
        z = None
        while True:
            payload, is_forward = yield
            X, y = payload['X'], payload['y']
            if is_forward:
                z = np.dot(X, w)
                if next_node:
                    data = {'X': z, 'y': y}
                    next_node.send((data, is_forward))
                else:
                    print(z)
            else:
                pass
            yield 0

    def sigmoid_node():
        a = None
        while True:
            payload, is_forward = yield
            z, y = payload['X'], payload['y']
            if is_forward:
                a = sigmoid(z)
                if next_node:
                    data = {'X': a, 'y': y}
                    next_node.send((data, is_forward))
                else:
                    print(a)
            else:
                pass
            yield 0

    if type_node == 'input':
        return input_node()
    elif type_node == 'linear':
        return linear_node()
    elif type_node == 'sigmoid':
        return sigmoid_node()
    else:
        return input_node()

if __name__ == '__main__':
    o = make_node('linear', None, shape=(5, 1))
    l3_act = make_node('sigmoid', o)
    l3_linear = make_node('linear', l3_act, shape=(10, 5))
    l2_act = make_node('sigmoid', l3_linear)
    l2_linear = make_node('linear', l2_act, shape=(15, 10))
    l1_act = make_node('sigmoid', l2_linear)
    l1_linear = make_node('linear', l1_act, shape=(2, 15))
    input_node = make_node('input', l1_linear)

    X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
    y = np.array([0, 0, 0, 1])

    next(input_node)
    next(l1_act)
    next(l1_linear)
    next(l2_act)
    next(l2_linear)
    next(l3_act)
    next(l3_linear)
    next(o)

    data = {'X': X, 'y': y}
    input_node.send((data, True))
