public class DecoratorTestDriven implements TestDriven {
    public void execute() {
        Computer computer = new Computer();
        computer = new Disk(computer);
        computer = new CD(computer);
        computer = new Monitor(computer);
        System.out.println(computer.description());
    }
}