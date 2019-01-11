package hpdp.forms;


import hpdp.Region;

import java.util.List;
import java.util.ArrayList;
import hpdp.Table;

public class CompositeTable extends Region{



    public Table table;
 /*   public enum HeaderLevel{
        LVL_1,LVL_2
    }
*/
    //   public HeaderLevel headerLevel;

    public CompositeTable(){

        super();
        this.exposedText = "";
        this.region = false;
        this.table = new Table();


    }




    @Override
    public String expose(){
        double stringWidth = 0;

        for (List<String> row : table.getRows()) {
            for (String value: row){
                stringWidth = stringWidth + ((value.length()*5.0)+15.0);
            }
            break;
        }
        if (213.34941 >stringWidth){
            size[0] = 213.34941;
        }
        else{
            size[0] = stringWidth;//(table.getColumnCount()*15);
        }

        size[1] =  (table.getRows().size()*10.362959);
        double iDisplacement = 0.0;
        super.expose();
        // position[1]+=20.0;
        position[0] += getTopologyRegion(this).getPosition()[0] -40.0;

        int rowNumber  = 1;
        int index = 0;
        int maxWidth = 0;

        for (List<String> row : table.getRows()) {
            if ((rowNumber % 2) > 0){                                    // Odd, Header

                exposedText += "<defs>" +
                        "<linearGradient\n" +
                        "       id=\"linearGradient4359\"\n" +/*
                        "       x1=\"139.91182\"\n" +
                        "       y1=\"-279.92044\"\n" +
                        "       x2=\"139.91182\"\n" +
                        "       y2=\"-289.93881\">\n" +*/
                        "       x1=\"0%\"" +
                        "       y1=\"0%\"" +
                        "       x2=\"0%\"" +
                        "       y2=\"100%\">" +
                        "<stop\n" +
                        "         style=\"stop-color:#e3e3e3;stop-opacity:1;\"\n" +
                        "         offset=\"0%\"\n" +
                        "         id=\"stop4353\" />\n" +
                        "      <stop\n" +
                        "         style=\"stop-color:#e3e3e3;stop-opacity:0;\"\n" +
                        "         offset=\"100%\"\n" +
                        "         id=\"stop4355\" />\n" +
                        "    </linearGradient>"+

                         /*   exposedText += "<linearGradient\n" +

                                    "       id=\"linearGradient4367\"\n" +
                                    "       x1=\"0%\"" +
                                    "       y1=\"0%\"" +
                                    "       x2=\"0%\"" +
                                    "       y2=\"100%\">" +
                                    "      <stop\n" +
                                    "         style=\"stop-color:#e3e3e3;stop-opacity:1;\"\n" +
                                    "         offset=\"0\"\n" +
                                    "         id=\"stop4361\" />\n" +
                                    "      <stop\n" +
                                    "         style=\"stop-color:#e3e3e3;stop-opacity:0;\"\n" +
                                    "         offset=\"100%\"\n" +
                                    "         id=\"stop4363\" />\n" +
                                    "    </linearGradient>"+*/
                        "</defs>";
                exposedText +=
                        "<rect\n" +
                                "       style=\"display:inline;fill:url(#linearGradient4359);fill-opacity:1;stroke-width:0.22655451\"\n" +
                                //"       style=\"display:inline;fill:#e3e3e3;fill-opacity:1;stroke-width:0.22655451\"\n" +
                                "       id=\"rect5773-1-83\"\n" +
                                "       width=\""+(size[0])+"\"\n" +
                                "       height=\"11.362959\"\n" +
                                "       x=\"" + (position[0] + iDisplacement) + "\"\n" +
                                "       y=\"" +( position[1]+(8.0*index) )+ "\" />\n";
                for (String value : row) {



                    exposedText += "<text\n" +
                            //    "       xml:space=\"preserve\"\n" +
                            //"       style=\"font-style:normal;font-variant:normal;font-weight:normal;font-stretch:normal;font-size:9.04130268px;line-height:1.25;font-family:'Times New Roman';-inkscape-font-specification:'Times New Roman, Normal';font-variant-ligatures:normal;font-variant-caps:normal;font-variant-numeric:normal;font-feature-settings:normal;text-align:start;letter-spacing:0px;word-spacing:0px;writing-mode:lr-tb;text-anchor:start;fill:#4e4e4e;fill-opacity:1;stroke:none;stroke-width:0.42381126\"\n" +
                            "         style=\"font-style:normal;font-variant:normal;font-weight:normal;font-stretch:normal;font-size:9.04130268px;font-family:'Times New Roman';text-align:start;writing-mode:lr-tb;text-anchor:start;fill:#4e4e4e;fill-opacity:1;stroke-width:0.42381126\"" +
                            //     "       x=\"31.853239\"\n" +
                            //    "       y=\"-313.07266\"\n" +
                            "       id=\"text107-29\"\n" +
                            //     "       transform=\"scale(1.1109935,0.90009527)\"" +
                            "       x=\"" + (position[0] + 3.0 +iDisplacement) + "\"\n" +
                            "       y=\"" + (position[1]+8.0+(8.0*index)) + "\" "+
                            ">" + value +" </text>";
                    iDisplacement = iDisplacement + (value.length()*5.0)+15.0;
                    //  iDisplacement += (value.length()*3)+15;
                }


            }
            else {

                iDisplacement = 0.0;
                exposedText += "<rect\n" +
                        "       style=\"display:inline;fill:#efefef;fill-opacity:0.58208953;stroke-width:0.33232033\"\n" +
                        "       id=\"rect5773-1-8\"\n" +
                        "       width=\""+(size[0])+"\"\n" +
                        "       height=\"11.362959\"\n" +
                        "       x=\"" + (position[0] + iDisplacement) + "\"\n" +
                        "       y=\"" +( position[1]+(8.0*index) )+ "\" />\n";
                int columnIndex = 0;
                for (String value : row) {

                    if (columnIndex > 0){
                        iDisplacement = iDisplacement + (((String)(table.getRows().get(0).get(columnIndex-1))).length()*5.0)+15.0;
                    }
                    exposedText += "<text\n" +
                            //    "       xml:space=\"preserve\"\n" +
                            //"       style=\"font-style:normal;font-variant:normal;font-weight:normal;font-stretch:normal;font-size:9.04130268px;line-height:1.25;font-family:'Times New Roman';-inkscape-font-specification:'Times New Roman, Normal';font-variant-ligatures:normal;font-variant-caps:normal;font-variant-numeric:normal;font-feature-settings:normal;text-align:start;letter-spacing:0px;word-spacing:0px;writing-mode:lr-tb;text-anchor:start;fill:#4e4e4e;fill-opacity:1;stroke:none;stroke-width:0.42381126\"\n" +
                            "         style=\"font-style:normal;font-variant:normal;font-weight:normal;font-stretch:normal;font-size:9.04130268px;font-family:'Times New Roman';text-align:start;writing-mode:lr-tb;text-anchor:start;fill:#4e4e4e;fill-opacity:1;stroke-width:0.42381126\"" +
                            //     "       x=\"31.853239\"\n" +
                            //    "       y=\"-313.07266\"\n" +
                            "       id=\"text107-29\"\n" +
                            //         "       transform=\"scale(1.1109935,0.90009527)\"" +
                            "       x=\"" + (position[0] + 3.0 +iDisplacement) + "\"\n" +
                            "       y=\"" + (position[1]+8.0+(8.0*index)) + "\" "+
                            ">" + value +" </text>";


                    columnIndex = columnIndex + 1;
                }

            }
            ++rowNumber;
            ++index;
        }

        return exposedText;
    }


}
