package hpdp.shapes.Chart;


import hpdp.Topology;
import java.util.List;
import java.util.ArrayList;

public class Legend extends Topology {

    public LegendStyle legendStyle = LegendStyle.GRAPH;
    public String legendValue = "";

    public enum LegendStyle{
        GRAPH,COLOR_INDICATOR,AREA
    }


    @Override
    public String expose(){


        if (legendStyle.equals(LegendStyle.GRAPH)) {
            double jIncrease = 624.45135 - 14.36239 - 14.36239 - 30.11695 - 21.33346;

            exposedText += "<text\n" +
                    "       style=\"font-style:normal;font-variant:normal;font-weight:normal;font-stretch:normal;font-size:5.58980036px;font-family:'Times New Roman';fill:#4e4e4e;fill-opacity:1;stroke-width:0.26202187\"   " +
                    "       x=\"" + (position[0] + jIncrease) + "\"\n" +
                    "       y=\"" + position[1] + "\"\n" +
                    "       id=\"text1067\"\n" +
                    // "       transform=\"scale(1.0080528,0.99201152)\"" +
                    ">Pass</text>\n";


            exposedText += "<rect\n" +
                    "       id=\"rect165\"\n" +
                    "       width=\"9.8988867\"\n" +
                    "       height=\"4.3904738\"\n" +
                    "       x=\"" + (position[0] + jIncrease) + "\"\n" +
                    "       y=\"" + (position[1] + 5.0) + "\"\n" +
                    "       style=\"fill:#7ea338;fill-opacity:0.68235294;stroke-width:0.26202187\"\n" +
                    "       ry=\"1.147568\" />\n";
            jIncrease += 14.36239;


            exposedText += "<text\n" +
                    "       style=\"font-style:normal;font-variant:normal;font-weight:normal;font-stretch:normal;font-size:5.58980036px;font-family:'Times New Roman';fill:#4e4e4e;fill-opacity:1;stroke-width:0.26202187\"   " +
                    "       x=\"" + (position[0] + jIncrease) + "\"\n" +
                    "       y=\"" + position[1] + "\"\n" +
                    "       id=\"text1067\"\n" +
                    // "       transform=\"scale(1.0080528,0.99201152)\"" +
                    ">Fail</text>\n";

            exposedText += "<rect\n" +
                    "       id=\"rect165-6\"\n" +
                    "       width=\"9.8988867\"\n" +
                    "       height=\"4.3904738\"\n" +
                    "       x=\"" + (position[0] + jIncrease) + "\"\n" +
                    "       y=\"" + (position[1] + 5.0) + "\"\n" +
                    "       style=\"fill:#cd544a;fill-opacity:0.55769228;stroke-width:0.26202187\"\n" +
                    "       ry=\"1.3562168\" />\n";
            jIncrease += 14.36239;

            exposedText += "<text\n" +
                    "       style=\"font-style:normal;font-variant:normal;font-weight:normal;font-stretch:normal;font-size:5.58980036px;font-family:'Times New Roman';fill:#4e4e4e;fill-opacity:1;stroke-width:0.26202187\"   " +
                    "       x=\"" + (position[0] + jIncrease) + "\"\n" +
                    "       y=\"" + position[1] + "\"\n" +
                    "       id=\"text1067\"\n" +
                    // "       transform=\"scale(1.0080528,0.99201152)\"" +
                    ">In Progress</text>\n";
            exposedText +=
                    "    <rect\n" +
                            "       id=\"rect165-3\"\n" +
                            "       width=\"25.653454\"\n" +
                            "       height=\"4.3904738\"\n" +
                            "       x=\"" + (position[0] + jIncrease) + "\"\n" +
                            "       y=\"" + (position[1] + 5.0) + "\"\n" +
                            "       style=\"fill:#c2c2fc;fill-opacity:0.4;stroke-width:0.42181039\"\n" +
                            "       ry=\"1.2518923\" />\n";
            jIncrease += 30.11695;

            exposedText += "<text\n" +
                    "       style=\"font-style:normal;font-variant:normal;font-weight:normal;font-stretch:normal;font-size:5.58980036px;font-family:'Times New Roman';fill:#4e4e4e;fill-opacity:1;stroke-width:0.26202187\"   " +
                    "       x=\"" + (position[0] + jIncrease) + "\"\n" +
                    "       y=\"" + position[1] + "\"\n" +
                    "       id=\"text1067\"\n" +
                    // "       transform=\"scale(1.0080528,0.99201152)\"" +
                    ">Broken</text>\n";
            exposedText +=
                    "    <rect\n" +
                            "       id=\"rect165-2\"\n" +
                            "       width=\"16.869934\"\n" +
                            "       height=\"4.3904738\"\n" +
                            "       x=\"" + (position[0] + jIncrease) + "\"\n" +
                            "       y=\"" + (position[1] + 5.0) + "\"\n" +
                            "       style=\"fill:#ebc546;fill-opacity:0.4;stroke-width:0.34205902\"\n" +
                            "       ry=\"1.4605412\" />\n";

            jIncrease += 21.33346;

            exposedText += "<text\n" +
                    "       style=\"font-style:normal;font-variant:normal;font-weight:normal;font-stretch:normal;font-size:5.58980036px;font-family:'Times New Roman';fill:#4e4e4e;fill-opacity:1;stroke-width:0.26202187\"   " +
                    "       x=\"" + (position[0] + jIncrease) + "\"\n" +
                    "       y=\"" + position[1] + "\"\n" +
                    "       id=\"text1067\"\n" +
                    // "       transform=\"scale(1.0080528,0.99201152)\"" +
                    ">Not Started</text>\n";
            exposedText +=
                    "    <rect\n" +
                            "       id=\"rect165-9\"\n" +
                            "       width=\"26.071718\"\n" +
                            "       height=\"4.3904738\"\n" +
                            "       x=\"" + (position[0] + jIncrease) + "\"\n" +
                            "       y=\"" + (position[1] + 5.0) + "\"\n" +
                            "       style=\"fill:#adadad;fill-opacity:0.26859508;stroke-width:0.42523509\"\n" +
                            "       ry=\"1.4605412\" />\n";
        }
        else if (legendStyle.equals(LegendStyle.AREA)){
                double jIncrease = 154.173+30.0;//624.45135 - 14.36239 - 14.36239 - 30.11695 - 21.33346;

                exposedText += "<text\n" +
                        "       style=\"font-style:normal;font-variant:normal;font-weight:normal;font-stretch:normal;font-size:5.58980036px;font-family:'Times New Roman';fill:#4e4e4e;fill-opacity:1;stroke-width:0.26202187\"   " +
                        "       x=\"" + (position[0] + jIncrease) + "\"\n" +
                        "       y=\"" + position[1] + "\"\n" +
                        "       id=\"text1067\"\n" +
                        // "       transform=\"scale(1.0080528,0.99201152)\"" +
                        ">Pass</text>\n";


                exposedText += "<rect\n" +
                        "       id=\"rect165\"\n" +
                        "       width=\"9.8988867\"\n" +
                        "       height=\"4.3904738\"\n" +
                        "       x=\"" + (position[0] + jIncrease) + "\"\n" +
                        "       y=\"" + (position[1] + 5.0) + "\"\n" +
                        "       style=\"fill:#7ea338;fill-opacity:0.68235294;stroke-width:0.26202187\"\n" +
                        "       ry=\"1.147568\" />\n";
              //  jIncrease += 14.36239;


                exposedText += "<text\n" +
                        "       style=\"font-style:normal;font-variant:normal;font-weight:normal;font-stretch:normal;font-size:5.58980036px;font-family:'Times New Roman';fill:#4e4e4e;fill-opacity:1;stroke-width:0.26202187\"   " +
                        "       x=\"" + (position[0] + jIncrease) + "\"\n" +
                        "       y=\"" + (position[1] + 18.0) + "\"\n" +
                        "       id=\"text1067\"\n" +
                        // "       transform=\"scale(1.0080528,0.99201152)\"" +
                        ">Fail</text>\n";

                exposedText += "<rect\n" +
                        "       id=\"rect165-6\"\n" +
                        "       width=\"9.8988867\"\n" +
                        "       height=\"4.3904738\"\n" +
                        "       x=\"" + (position[0] + jIncrease) + "\"\n" +
                        "       y=\"" + (position[1] + 23.0) + "\"\n" +
                        "       style=\"fill:#cd544a;fill-opacity:0.55769228;stroke-width:0.26202187\"\n" +
                        "       ry=\"1.3562168\" />\n";
               // jIncrease += 14.36239;


        }
        else if (legendStyle.equals(LegendStyle.COLOR_INDICATOR)){
            exposedText += "<text\n" +
                    "         style=\"font-style:normal;font-variant:normal;font-weight:normal;font-stretch:normal;font-size:9.04130745px;font-family:'Times New Roman';fill:#4e4e4e;fill-opacity:1;opacity:0.433;stroke-width:0.42381126;\"\n" +
                    "       x=\"" + (position[0]) + "\"\n" +
                    "       y=\"" + (position[1]) + "\"\n" +
                    "       id=\"text107-1-2-8-9-3-0-7\"\n" +
                    //"       transform=\"scale(1.1109935,0.90009527)\"><tspan\n" +

                    "        >"+legendValue+"</text>";
        }
        return exposedText;
    }


}
