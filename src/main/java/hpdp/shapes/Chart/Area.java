package hpdp.shapes.Chart;

import hpdp.Topology;

public class Area extends Topology {

    public AreaType areaType = AreaType.SCATTER;
    public enum AreaType{
        SCATTER,AREA
    }

    public double quantityIncrement = 0.0;

    public Area() {

        super();
    }

    @Override
    public String expose(){

        if (areaType.equals(AreaType.SCATTER)) {
            double gridIOffset = 0.0;
            boolean even = true;
            while (gridIOffset < (size[1] - quantityIncrement - quantityIncrement)) {//11.18734
                if (even) {

                    exposedText += "<rect style=\"fill:#f4f4f4;fill-opacity:0.15384617;stroke:none;stroke-width:0.9375;stroke-opacity:0.61538463\" id=\"rectA" + gridIOffset + "5982\" width=\"" + (size[0] + 7.584706 + 36.620815) + "\" height=\"10.0\" x=\"" + position[0] + "\" y=\"" + (position[1] + gridIOffset) + "\" />";//424.45135\" "+size[1]+
                    even = false;
                } else {
                    even = true;
                }
      /*      exposedText += "<path\n" +
                    "       style=\"display:inline;fill:#767676;fill-opacity:1;stroke:#d8d8d8;stroke-width:0.5125106px;stroke-linecap:butt;stroke-opacity:1\"\n" +
                    "       d=\"m " + position[0] + "," + (position[1] + gridIOffset )+ "  h " + (size[0] + 7.584706 + 36.620815) + "\"\n" +
                    "       id=\"path3754-5\"\n" +
                    "       sodipodi:nodetypes=\"cc\" />\n";*/
                gridIOffset = gridIOffset + quantityIncrement;
            }
            gridIOffset = 0.0;
            while (gridIOffset < (size[1] - quantityIncrement)) {
                //  exposedText = "<rect style=\"fill:#f4f4f4;fill-opacity:0.15384617;stroke:none;stroke-width:1.16297209;stroke-opacity:0.61538463\" id=\"rect5982\" width=\""+ (size[0] + 7.584706 + 36.620815) +"\" height=\"10\" x=\""+position[0]+"\" y=\""+ (position[1] + gridIOffset )+ "\" />";//424.45135\" "+size[1]+

                exposedText += "<path\n" +
                        "       style=\"display:inline;fill:#767676;fill-opacity:1;stroke:#d8d8d8;stroke-width:0.5125106px;stroke-linecap:butt;stroke-opacity:1\"\n" +
                        "       d=\"m " + position[0] + "," + (position[1] + gridIOffset) + "  h " + (size[0] + 7.584706 + 36.620815) + "\"\n" +
                        "       id=\"path3754-5\"\n" +
                        "       sodipodi:nodetypes=\"cc\" />\n";
                gridIOffset = gridIOffset + quantityIncrement;
            }
        }
        else if (areaType.equals(AreaType.AREA)){

        }
        return exposedText;
    }


}
