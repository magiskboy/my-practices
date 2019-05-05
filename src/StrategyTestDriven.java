public class StrategyTestDriven implements TestDriven{
    public void execute() {
        Vehicle racer = new Racer();
        Vehicle jet = new Jet();
        racer.go();
        jet.go();
        jet.setGoAlgorithm(new FlyAlgorithm());
        jet.go();
        jet.setGoAlgorithm(new DriveAlgorithm());
        jet.go();
    }
}