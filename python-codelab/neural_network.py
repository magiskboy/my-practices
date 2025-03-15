import numpy as np

def sigmoid_fn(z):
    return 1.0 / (1 + np.exp(-z))

def relu_fn(z):
    if z <= 0:
        return 0
    else:
        return z

def logloss_fn(y, y_hat):
    return np.multiply(np.log(y_hat), y) + np.multiply(np.log(1 - y_hat), (1 - y))

def mean_squared_error(y, y_hat):
    return ((y - y_hat)**2).mean()

def derivative_sigmoid() 

def initial_parameters(L, X, y):
    """Initial parameters for network
    Parameters:
    -----------
    L: list, number of node in layer
    X: numpy array, shape (m, n)
    y: numpy array, shape (m, 1)

    Returns:
    --------
    w: list of numpy array, len(L) + 1 element
    """
    w = []
    L.append(X.shape[1])
    for i in range(len(L)-1):
        w.append(2 * np.random.randn(L[i], L[i+1]) * 0.001)
    w.append(np.random.randn(L[-1], y.shape[1]))
    return w

def forward(X, y, parameters, activation='sigmoid'):
    """Forward flow in netword
    Parameters:
    -----------
    X: numpy array, shape (m, n)
    y: numpy array, shape (m, 1)
    parameters: list of numpy array

    Returns:
    -------
    a: list of numpy array, activation of network, len(parameters) + 1 element
    """
    a = [None] * (len(parameters) + 2)
    z = [None] * (len(parameters) + 2)
    a[0] = X
    a[-1] = y
    for i in range(1, len(parameters)):
        z[i] = np.dot(a[i-1], parameters[i-1])
        if activation == 'sigmoid':
            a[i] = sigmoid_fn(z[i])
    z[-2] = np.dot(a[-3], parameters[-1])
    a[-2] = z[-2]

    return a, z

def backward(a, z, parameters, loss_fn, activation):
    cost = loss_fn(a[-1], a[-2])

    if activation == 'sigmoid':
        pass
    elif activation == 'relu':
        pass

    return cost


def update_parameters(dW, parameters):
    pass


if __name__ == '__main__':
    X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
    y = np.array([[0], [1], [1], [1]])
    w = initial_parameters([2], X, y)
    a, z = forward(X, y, w)
    error = backward(a, z, w, mean_squared_error)
    print(error)
