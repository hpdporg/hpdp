package hpdp;

public class Padding {

    double[] innerI;             // Horizontal on interior
    double[] innerJ;             // Vertical on interior
    double[] outerI;             // Horizontal bordering interior
    double[] outerJ;             // Vertical bordering interior


    public Padding(){
        innerI = new double[2];
        innerJ = new double[2];
        outerI = new double[2];
        outerJ = new double[2];
    }

}
