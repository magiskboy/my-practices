interface GoAlgorithm {
    public void go();
}

abstract class Vehicle {
    private GoAlgorithm goAlgorithm;

    public Vehicle() {

    }

    public void setGoAlgorithm(GoAlgorithm algorithm) {
        goAlgorithm = algorithm;
    }

    public void go() {
        goAlgorithm.go();
    }
}

class FlyAlgorithm implements GoAlgorithm {
    public void go() {
        System.out.println("Now I'm flying");
    }
}

class DriveAlgorithm implements GoAlgorithm {
    public void go() {
        System.out.println("Now I'm driving");
    }
}

class Racer extends Vehicle {
    public Racer () {
        setGoAlgorithm(new DriveAlgorithm());
    }
}

class Jet extends Vehicle {
    public Jet () {
        setGoAlgorithm(new DriveAlgorithm());
    }
}
