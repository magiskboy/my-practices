import javax.xml.crypto.Data;
import java.util.Observable;
import java.util.Observer;

class Database extends Observable {
    private String operation;
    private String record;

    public void editRecord(String operation, String record) {
        this.operation = operation;
        this.record = record;
        setChanged();
        notifyObservers();
    }

    public String getOperation() {
        return this.operation;
    }

    public String getRecord() {
        return this.record;
    }
}

class Archiver implements Observer {
    public void update(Observable obs, Object record) {
        System.out.println("This archiver say a " + ((Database)obs).getOperation()+ " operation was performed on "
                           + ((Database)obs).getRecord());
    }
}

class Client implements Observer {
    public void update(Observable obs, Object record) {
        System.out.println("This client say a " + ((Database)obs).getOperation()+ " operation was performed on "
                + ((Database)obs).getRecord());
    }
}

class Boss implements Observer {
    public void update(Observable obs, Object record) {
        System.out.println("This boss say a " + ((Database)obs).getOperation()+ " operation was performed on "
                + ((Database)obs).getRecord());
    }
}
