package hpdp.forms;

import hpdp.shapes.Chart.Area;
import hpdp.shapes.Chart.Chart;
import hpdp.shapes.Chart.Trace;
import hpdp.shapes.Chart.Legend.LegendStyle;

public class AreaChart extends Chart{

    public double quantityIncrement = 0.0;
    public double iQuantityIncrement = 0.0;
    public String[] plots = null;



    public AreaChart(){
        super(false);
        size[0] = 624.45135;
        size[1] = 376.78464 ;
       // iAxisLabel.setSize(size);
       // jAxisLabel.setSize(size);
        legend.setSize(size);
        legend.legendStyle = LegendStyle.AREA;

    }

    @Override
    public String expose() {



        super.expose();
        //size[1] = 176.78464 ;
        position[1]-=200.0;
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
     //   boolean even = true;


        double[] legendPosition = new double[2];
       legendPosition[0] = legend.getPosition()[0] + position[0];
        legendPosition[1] = legend.getPosition()[1] + position[1];

      //  legendPosition[1] -= 30.0;
       legend.setSize(size);
        legend.setPosition(legendPosition);


        area.setSize(size);
        area.quantityIncrement = quantityIncrement;
        area.setPosition(position);

        area.areaType = Area.AreaType.AREA;


       // System.out.println("Pos: " + position[1]);
        int plotIndex = 0;
        for (String plotValue : plots){
            double iIndex = 0.0;
            exposedText += "  <polygon points=\"";

            if (plotIndex == 0){
                exposedText+= ""+(int)(position[0])+","+(int)(position[1])+" ";

            }
            else{
                exposedText+= ""+(int)(position[0])+","+(int)(position[1]+54.237)+" ";
               // exposedText+= ""+(int)(position[0])+","+(int)(position[1]+54.237)+" ";
            }
            String lastColor = "none";
            for (Trace trace : traces){
                if (trace.values.get(0)[0].equals(plotValue)){

 //                   System.out.println("AR: "+trace.values.get(0)[0]+ " " +trace.coords.size() + " " + trace.coords.get(0)[0] +", " + trace.coords.get(0)[1]);
                    exposedText+= ""+(int)((iIndex*iQuantityIncrement)+position[0])+","+(int)(position[1]+trace.coords.get(0)[1])+" ";
                    lastColor = trace.getColor(plotValue);
                    iIndex += 1.0;
   //                 System.out.println(""+(int)((iIndex*iQuantityIncrement)+position[0])+","+(int)(position[1]+trace.coords.get(0)[1])+" ");
                }
                else {

     //               System.out.println("AR: "+trace.values.get(0)[0]+ " " +trace.coords.size() + " " + trace.coords.get(0)[0] +", " + trace.coords.get(0)[1]);
                    exposedText+= ""+(int)((iIndex*iQuantityIncrement)+position[0])+","+(int)(position[1]+trace.coords.get(0)[1])+" ";

                    iIndex += 1.0;
       //             System.out.println(""+(int)((iIndex*iQuantityIncrement)+position[0])+","+(int)(position[1]+trace.coords.get(0)[1])+" ");
                }


            }
            if (plotIndex == 0){
                exposedText+= ""+(int)(position[0]+154.173)+","+(int)(position[1])+" ";
           //     System.out.println("Oner" + exposedText);
            }
            else{
              //  exposedText+= ""+(int)(position[0]+154.173)+","+(int)(position[1])+" ";
                exposedText+= ""+(int)(position[0]+154.173)+","+(int)(position[1]+54.237)+" ";
            }
           exposedText+= "\"  style=\"fill-opacity:0.68235294;stroke-opacity:0.2\" fill=\"#"+lastColor+"\" stroke=\"black\" />";
            ++plotIndex;
//break;
        }





        area.expose();

       /*exposedText += "<path" +
                "    style=\"fill:none;stroke:#616161;stroke-width:0.6868906;stroke-linecap:butt;stroke-dasharray:none;stroke-opacity:0.9375\"" +
                // "    d=\"m 72.943295,-503.09298 -0.04505,176.78464 c 0,0 7.584706,-6.8177 36.620815,-11.18734 34.4803,-5.18894 97.22055,-2.7759 218.53298,10.30552\"" +
                "    d=\"m "+position[0]+","+position[1]+" -0.04505,"+(size[1])+" c 0,0 7.584706,-6.8177 36.620815,-"+(quantityIncrement-0.9375)+" 34.4803,-3.18894 97.22055,-2.7759 "+size[0]+",10.30552\\\"\" +//218.53298,10.30552\"" +
                "    id=\"path4748\"/>";
*/



        return exposedText;
    }

}
