package hpdp.forms;

import hpdp.shapes.Chart.Chart;
import hpdp.shapes.Chart.Trace;
import hpdp.shapes.Chart.Legend.LegendStyle;

public class ColorIndicator extends Chart{

    public double quantityIncrement = 0.0;
    public double iQuantityIncrement = 0.0;
    public String legendValue = "";

    public ColorIndicator(){
        super(false);
        size[0] = 624.45135;
        size[1] = 376.78464 ;

        legend.setSize(size);
    }

    @Override
    public String expose() {



        super.expose();
        //size[1] = 176.78464 ;

        //    position[1] +=40.0;
    //    //System.out.println("B: " + position[1]);
     //   //System.out.println("C: " +getTopologyRegion(this).getPosition()[1]);
  //      position[1] = getTopologyRegion(this).getPosition()[1];
     //   position[1] += 40.0;//size[1] + 40.0;
        position[0] += getTopologyRegion(this).getPosition()[0];
 //       position[1] += 40.0;
       // position[0] += 40.0;
        //size[1] += getTopologyRegion(this).getSize()[1];
        //size[1]+= 40.0;


        double[] legendPosition = new double[2];

//        legendPosition[1] -= 30.0;
       legend.setSize(size);
        legend.setPosition(legendPosition);
        legend.legendValue = legendValue;
        legendPosition[0] =  position[0] + (77.813194 /2.0) - (legendValue.length()*3.0);
        legendPosition[1] =  position[1] + (18.725918/2.0) + 3.0;


        exposedText += "<rect\n" +
                "       id=\"rect165-94-4\"\n" +
                "       width=\"77.813194\"\n" +
                "       height=\"18.725918\"\n" +
                "       x=\""+ position[0]+"\"\n" +
                "       y=\""+ position[1]+"\"\n" +
                "       style=\"display:inline;fill:#"+Trace.getColor(legend.legendValue)+";fill-opacity:0.68235294;stroke-width:1.64549458\"\n" +
                "       ry=\"5.7574391\" />\n" +
                " ";






        return exposedText;
    }

}
