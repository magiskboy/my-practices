public class ChainableOfReposibilityTestDriven implements TestDriven {
    public void execute() {
        final int FRONT_END_HELP = 1;
        final int INTERMEDIATE_HELP = 2;
        final int GENERAL_HELP = 3;

        Application app = new Application();
        Intermediate intermediate = new Intermediate(app);
        FrontEnd frontEnd = new FrontEnd(intermediate);

        frontEnd.getHelp(GENERAL_HELP);
        frontEnd.getHelp(INTERMEDIATE_HELP);
        frontEnd.getHelp(FRONT_END_HELP);
    }
}