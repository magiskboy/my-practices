class ObserverTestDriven implements TestDriven{
    public void execute() {
        Database database = new Database();
        Archiver archiver = new Archiver();
        Client client = new Client();
        Boss boss = new Boss();

        database.addObserver(archiver);
        database.addObserver(client);
        database.addObserver(boss);

        database.editRecord("delete", "record 1");
    }
}