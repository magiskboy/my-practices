class Computer {
    public Computer() {

    }

    public String description() {
        return "You are getting a computer";
    }
}

abstract class ComponentDecorator extends Computer {
    public abstract String description();
}

class Disk extends ComponentDecorator {
    Computer computer;

    public Disk(Computer c) {
        computer = c;
    }

    public String description() {
        return computer.description() + " and a disk";
    }
}

class CD extends ComponentDecorator {
    Computer computer;

    public CD(Computer c) {
        computer = c;
    }

    public String description() {
        return computer.description() + " and a CD";
    }
}

class Monitor extends ComponentDecorator {
    Computer computer;

    public Monitor(Computer c) {
        computer = c;
    }

    public String description() {
        return computer.description() + " and a monitor";
    }
