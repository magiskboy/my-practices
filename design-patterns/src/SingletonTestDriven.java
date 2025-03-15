public class SingletonTestDriven implements TestDriven{
    public void execute() {
        SingletonDatabase database = SingletonDatabase.getInstance("production");
        System.out.println()
    }
}