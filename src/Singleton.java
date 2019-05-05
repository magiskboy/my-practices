class SingletonDatabase {
    private String name;

    private static SingletonDatabase instance;

    private SingletonDatabase() {
        this.name = "";
    }

    public static SingletonDatabase getInstance(String name) {
        if (instance == null) {
            instance = new SingletonDatabase();
        }
        return instance;
    }

    public String getName() {
        return this.name;
    }
}