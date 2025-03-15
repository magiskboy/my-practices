abstract class Connection {
    abstract String description();
}

class SecureMySqlConnection extends Connection {
    public String description() {
        return "MySqlConnection secure";
    }
}

class SecureOracleConnection extends Connection {
    public String description() {
        return "OracleConnection secure";
    }
}

abstract class FactoryConnection {
    public FactoryConnection() {
    }

    abstract protected Connection createConnection(String type);
}

class SecureFactoryConnection extends FactoryConnection {
    public Connection createConnection(String type) {
        if (type.equals("MySql")) {
            return new SecureMySqlConnection();
        }
        else if (type.equals("Oracle")) {
            return new SecureOracleConnection();
        }
        else return null;
    }
}
