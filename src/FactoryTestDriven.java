public class FactoryTestDriven implements TestDriven {
    public void execute() {
        FactoryConnection factory = new SecureFactoryConnection();
        Connection connection = factory.createConnection("Oracle");
        System.out.println(connection.description());
    }
}