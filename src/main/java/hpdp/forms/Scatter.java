package hpdp.forms;

import hpdp.shapes.Chart.Chart;
import hpdp.shapes.Chart.Trace;

public class Scatter extends Chart{

    public double quantityIncrement = 0.0;
    public double iQuantityIncrement = 0.0;

    public Scatter(){
        super();
        size[0] = 624.45135;
        size[1] = 376.78464 ;
        iAxisLabel.setSize(size);
        jAxisLabel.setSize(size);
        legend.setSize(size);
    }

    @Override
    public String expose() {



        super.expose();
        //size[1] = 176.78464 ;
        position[1]-=10.0;
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


        double gridIOffset = 0.0;
        boolean even = true;


        double[] legendPosition = new double[2];
       legendPosition[0] = legend.getPosition()[0] + position[0];
        legendPosition[1] = legend.getPosition()[1] + position[1];

        legendPosition[1] -= 30.0;
       legend.setSize(size);
        legend.setPosition(legendPosition);


        area.setSize(size);
        area.quantityIncrement = quantityIncrement;
        area.setPosition(position);

        area.expose();

        exposedText += "<path" +
                "    style=\"fill:none;stroke:#616161;stroke-width:0.6868906;stroke-linecap:butt;stroke-dasharray:none;stroke-opacity:0.9375\"" +
                // "    d=\"m 72.943295,-503.09298 -0.04505,176.78464 c 0,0 7.584706,-6.8177 36.620815,-11.18734 34.4803,-5.18894 97.22055,-2.7759 218.53298,10.30552\"" +
                "    d=\"m "+position[0]+","+position[1]+" -0.04505,"+(size[1])+" c 0,0 7.584706,-6.8177 36.620815,-"+(quantityIncrement-0.9375)+" 34.4803,-3.18894 97.22055,-2.7759 "+size[0]+",10.30552\\\"\" +//218.53298,10.30552\"" +
                "    id=\"path4748\"/>";




        jAxisLabel.setSize(size);
        jAxisLabel.setPosition(position);
        jAxisLabel.defineRangeQuantities();
        jAxisLabel.expose();

        for (Trace trace : traces){
            double[] traceSize = new double[2];
            double[] tracePosition = new double[2];
            traceSize[0] = trace.getSize()[0] + size[0];
            traceSize[1] = trace.getSize()[1] + size[1];
            tracePosition[0] = trace.getPosition()[0] + position[0];
            tracePosition[1] = trace.getPosition()[1] + position[1];


            trace.setSize(traceSize);
            trace.setPosition(tracePosition);
            trace.quantityIncrement[0] = iQuantityIncrement;
            //System.out.println("Trace: " + tracePosition[1]);
            trace.expose();
        }

        return exposedText;
    }

}
