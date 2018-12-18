package hpdp.shapes.Chart;

import hpdp.Topology;
import java.util.List;
import java.util.ArrayList;

public class Trace extends Topology {

    List<String> values = null;
    List<String> valueLabels = null;

    public String[] data = null;


    public Trace() {

        super();


    }


    @Override
    public String expose(){

        double gridIOffset = 0.0;

        double xOffset = 0.0;

        System.out.println("POINT: "+position[0] + " "+ position[1]);
        exposedText += "<ellipse\n" +
                "       style=\"display:inline;fill:#759d27;fill-opacity:0.61568627;stroke-width:0.29709429\"\n" +
                "       id=\"path4827-6-03-6-6-9-8\"\n" +
                "       cx=\"" + (position[0] + 30.0 ) + "\"" +//159.56712\"\n" +
                "       cy=\"" + (position[1] ) + "\"" +//cy=\"-471.32864\"\n" +
                "       rx=\"2.5532577\"\n" +
                "       ry=\"2.5620646\" />\n";

        if (false) {
            while (gridIOffset < (size[1] - 11.18734)) {
                if (gridIOffset == 50.0) {
                    while (xOffset < (size[0] + 7.584706 + 36.620815 - 30.0)) {
                        exposedText += " <ellipse\n" +
                                "       style=\"display:inline;fill:#759d27;fill-opacity:0.03411765;stroke-width:0.28198448\"\n" +
                                "       id=\"path4827-6-4-9-76\"\n" +
                                "       cx=\"" + (position[0] + 30.0 + xOffset) + "\"" +//159.56712\"\n" +
                                "       cy=\"" + (position[1] + gridIOffset) + "\"" +//cy=\"-471.32864\"\n" +
                                "       rx=\"2.501524\"\n" +
                                "       ry=\"2.355818\" />\n" +
                                " ";
/*                    exposedText += "<ellipse\n" +
                            "       style=\"display:inline;fill:#759d27;fill-opacity:0.61568627;stroke-width:0.29709429\"\n" +
                            "       id=\"path4827-6-03-6-6-9-8\"\n" +
                            "       cx=\"" + (position[0] + 30.0 + yOffset) + "\"" +//159.56712\"\n" +
                            "       cy=\"" + (position[1] + gridIOffset) + "\"" +//cy=\"-471.32864\"\n" +
                            "       rx=\"2.5532577\"\n" +
                            "       ry=\"2.5620646\" />\n";*/
                        xOffset = xOffset + 0.5;
                    }
                }
                exposedText += "<ellipse\n" +
                        "       style=\"display:inline;fill:#759d27;fill-opacity:0.61568627;stroke-width:0.29709429\"\n" +
                        "       id=\"path4827-6-03-6-6-9-8\"\n" +
                        "       cx=\"" + (position[0] + 30.0 + gridIOffset) + "\"" +//159.56712\"\n" +
                        "       cy=\"" + (position[1] + gridIOffset) + "\"" +//cy=\"-471.32864\"\n" +
                        "       rx=\"2.5532577\"\n" +
                        "       ry=\"2.5620646\" />\n";
                gridIOffset = gridIOffset + 10.0;
            }
        }


        return exposedText;
    }



}
