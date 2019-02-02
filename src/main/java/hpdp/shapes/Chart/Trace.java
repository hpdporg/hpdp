package hpdp.shapes.Chart;

import hpdp.Time;
import hpdp.Topology;
import java.util.List;
import java.util.ArrayList;

public class Trace extends Topology {

    public List<String[]> values = null;
    List<String> valueLabels = null;
    public List<Double[]> coords = null;
    public Time minTime = null;
    public Time maxTime = null;
    public double[] quantityIncrement = null;


    public String[] data = null;
    public String[] linkPath = null;

    public Trace() {

        super();
        quantityIncrement = new double[2];
        quantityIncrement[0] = 0.0;
        quantityIncrement[1] = 0.0;

        coords = new ArrayList<>();

    }



    public static String getColor(String term){
        String color = null;

        if (term.equals("PASS")){
            color = "759d27";
        }
        else if (term.equals("FAIL")){
            color = "cd544a";
        }
        else if (term.equals("IN PROGRESS")){
            color = "c2c2fc";
        }
        else if (term.equals("BROKEN")){
            color = "ebc546";
        }
        else if (term.equals("NOT STARTED")){
            color = "acacac";
        }

        return color;
    }





    @Override
    public String expose(){


        String lastColor = "759d27";

        double gridIOffset = 0.0;

        double xOffset = 0.0;

        //System.out.println("POINT: "+position[0] + " "+ position[1]);

        int index = 0;
        double coordIDelta = 0.0;
        for (String[] value : values) {
            Double[] coord = coords.get(index);


            //System.out.println(coord[1] + "CO");

          //  long coord0Long = Long.parseLong(value[1]);
         //   coord[0] =iFromTimestamp(coord0Long);
          //  coord[0] = Double.parseDouble(value[1]);

            lastColor = getColor(value[2]);
            if ( (index == values.size()-1)) {
                if (linkPath != null) {
                    exposedText +="<a xlink:href=\""+linkPath[index]+"\"\n" +
                            "\t  target=\"_blank\">";
                }
                exposedText += "<ellipse\n" +
                        "       style=\"display:inline;fill:#"+lastColor+";fill-opacity:0.61568627;stroke-width:0.29709429\"\n" +
                        "       id=\"path4827-6-03-6-6-9-8\"\n" +
                        "       cx=\"" + (position[0] + 30.0 +  coord[0]) + "\"" +//159.56712\"\n" +
                        "       cy=\"" + (position[1] + coord[1]) + "\"" +//cy=\"-471.32864\"\n" +
                        "       rx=\"2.5532577\"\n" +
                        "       ry=\"2.5620646\" />\n";
                if (linkPath != null) {
                    exposedText += "</a>";
                }
            }
            else {
                /*   String[] prevValue = values.get(index-1);
                lastColor = getColor(prevValue[2]);*/
                Double[] priorCoord = null;
                if (index > 0) {
                    priorCoord = coords.get(index - 1);
                    coordIDelta = coords.get(index)[0] - coords.get(index - 1)[0];

                }
                else{
                    priorCoord = new Double[2];
                    priorCoord[0] = coord[0];
                    priorCoord[1] = 0.0;
                    coordIDelta = 1.0;
                }
                if (coordIDelta >=0.015) {
                    if (linkPath != null) {
                        exposedText +="<a xlink:href=\""+linkPath[index]+"\"\n" +
                                "\t  target=\"_blank\">";
                    }
                exposedText += "<ellipse\n" +
                        "       style=\"display:inline;fill:#" + lastColor + ";fill-opacity:0.61568627;stroke-width:0.29709429\"\n" +
                        "       id=\"path4827-6-03-6-6-9-8\"\n" +
                        "       cx=\"" + (position[0] + 30.0 + coord[0]) + "\"" +//159.56712\"\n" +
                        "       cy=\"" + (position[1] + coord[1]) + "\"" +//cy=\"-471.32864\"\n" +
                        "       rx=\"2.5532577\"\n" +
                        "       ry=\"2.5620646\" />\n";
                    if (linkPath != null){
                        exposedText += "</a>";
                    }

                    String[] nextvalue = values.get(index + 1);
                    Double[] nextCoord = coords.get(index + 1);
                    //    long nextCoord0Long = Long.parseLong(value[1]);
                    //   nextCoord[0] =iFromTimestamp(nextCoord0Long);
                    nextCoord[0] = coords.get(index + 1)[0];
                    //nextCoord[0] = Double.parseDouble(nextvalue[1]);
                    double increment = 0.0;
                    //   coord[0] = priorCoord[0] + 0.5;


                    while ((coord[0] + increment) < nextCoord[0]) {
                  /* exposedText += " <ellipse\n" +
                            "       style=\"display:inline;fill:#"+lastColor+";fill-opacity:0.03411765;stroke-width:0.28198448\"\n" +
                            "       id=\"path4827-6-4-9-76\"\n" +
                            "       cx=\"" + (position[0] + 30.0 + coord[0]) + "\"" +//159.56712\"\n" +
                            "       cy=\"" + (position[1] + coord[1]) + "\"" +//cy=\"-471.32864\"\n" +


                            //    "       cx=\"" + (position[0] + 30.0 + xOffset) + "\"" +//159.56712\"\n" +
                            //  "       cy=\"" + (position[1] + gridIOffset) + "\"" +//cy=\"-471.32864\"\n" +
                            "       rx=\"2.501524\"\n" +
                            "       ry=\"2.355818\" />\n" +
                            " ";*/
                        //  coord[0] = coord[0] + increment;
                        increment = increment + quantityIncrement[0];


                    }
                    exposedText += "<rect\n" +
                            "       style=\"display:inline;fill:#" + lastColor + ";fill-opacity:0.3411765;stroke-width:0.28198448\"\n" +
                            "       id=\"path4827-6-03-6-6-9-8\"\n" +
                            " width=\"" + increment + "\" height=\"4.711636\"" +
                            " x=\"" + (position[0] + 30.0 + coord[0]) + "\" y=\"" + (position[1] + coord[1] - 1.250762 - 1.250762) + "\" rx=\"3.4004979\"/>";
                }
                else{
               //    System.out.println("Too many points to represent visually. Too dense. " + coordIDelta  + " "+ coords.get(index)[0]+ " "+ coords.get(index - 1)[0]);
                 //   System.out.println("" + value[0]);
                }
            }
            ++index;

        }





        return exposedText;
    }



}
