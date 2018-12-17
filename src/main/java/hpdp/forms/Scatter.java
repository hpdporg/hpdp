package hpdp.forms;

import hpdp.shapes.Chart;

public class Scatter extends Chart{

    public Scatter(){
        super();
    }

    @Override
    public String expose() {

        size[0] = 424.45135;
        size[1] = 176.78464 ;

        super.expose();
        //size[1] = 176.78464 ;
        position[1]-=20.0;
        //    position[1] +=40.0;
    //    System.out.println("B: " + position[1]);
     //   System.out.println("C: " +getTopologyRegion(this).getPosition()[1]);
  //      position[1] = getTopologyRegion(this).getPosition()[1];
     //   position[1] += 40.0;//size[1] + 40.0;
        position[0] += getTopologyRegion(this).getPosition()[0];
 //       position[1] += 40.0;
       // position[0] += 40.0;
        //size[1] += getTopologyRegion(this).getSize()[1];
        //size[1]+= 40.0;


        double gridIOffset = 0.0;
        boolean even = true;
        while (gridIOffset <(size[1]-11.18734-10.0)) {
            if (even) {

                exposedText += "<rect style=\"fill:#f4f4f4;fill-opacity:0.15384617;stroke:none;stroke-width:1.16297209;stroke-opacity:0.61538463\" id=\"rectA"+gridIOffset+"5982\" width=\"" + (size[0] + 7.584706 + 36.620815) + "\" height=\"10.0\" x=\"" + position[0] + "\" y=\"" + (position[1] + gridIOffset) + "\" />";//424.45135\" "+size[1]+
                even = false;
            }
            else{
                even = true;
            }
      /*      exposedText += "<path\n" +
                    "       style=\"display:inline;fill:#767676;fill-opacity:1;stroke:#d8d8d8;stroke-width:0.5125106px;stroke-linecap:butt;stroke-opacity:1\"\n" +
                    "       d=\"m " + position[0] + "," + (position[1] + gridIOffset )+ "  h " + (size[0] + 7.584706 + 36.620815) + "\"\n" +
                    "       id=\"path3754-5\"\n" +
                    "       sodipodi:nodetypes=\"cc\" />\n";*/
            gridIOffset = gridIOffset + 10.0;
        }
        gridIOffset = 0.0;
        while (gridIOffset <(size[1]-11.18734)) {
          //  exposedText = "<rect style=\"fill:#f4f4f4;fill-opacity:0.15384617;stroke:none;stroke-width:1.16297209;stroke-opacity:0.61538463\" id=\"rect5982\" width=\""+ (size[0] + 7.584706 + 36.620815) +"\" height=\"10\" x=\""+position[0]+"\" y=\""+ (position[1] + gridIOffset )+ "\" />";//424.45135\" "+size[1]+

           exposedText += "<path\n" +
                    "       style=\"display:inline;fill:#767676;fill-opacity:1;stroke:#d8d8d8;stroke-width:0.5125106px;stroke-linecap:butt;stroke-opacity:1\"\n" +
                    "       d=\"m " + position[0] + "," + (position[1] + gridIOffset )+ "  h " + (size[0] + 7.584706 + 36.620815) + "\"\n" +
                    "       id=\"path3754-5\"\n" +
                    "       sodipodi:nodetypes=\"cc\" />\n";
            gridIOffset = gridIOffset + 10;
        }
        exposedText += "<path" +
                "    style=\"fill:none;stroke:#616161;stroke-width:0.6868906;stroke-linecap:butt;stroke-dasharray:none;stroke-opacity:0.9375\"" +
                // "    d=\"m 72.943295,-503.09298 -0.04505,176.78464 c 0,0 7.584706,-6.8177 36.620815,-11.18734 34.4803,-5.18894 97.22055,-2.7759 218.53298,10.30552\"" +
                "    d=\"m "+position[0]+","+position[1]+" -0.04505,"+(size[1])+" c 0,0 7.584706,-6.8177 36.620815,-11.18734 34.4803,-5.18894 97.22055,-2.7759 "+size[0]+",10.30552\\\"\" +//218.53298,10.30552\"" +
                "    id=\"path4748\"/>";

        gridIOffset = 0.0;
        double xOffset = 0.0;
        while (gridIOffset <(size[1]-11.18734)) {
            if (gridIOffset == 50.0){
                while (xOffset < (size[0] + 7.584706 + 36.620815-30.0)) {
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
                "       cx=\""+(position[0]+30.0+gridIOffset)+"\"" +//159.56712\"\n" +
                "       cy=\""+(position[1] + gridIOffset )+"\"" +//cy=\"-471.32864\"\n" +
                "       rx=\"2.5532577\"\n" +
                "       ry=\"2.5620646\" />\n";
            gridIOffset = gridIOffset + 10.0;
        }

        gridIOffset = 0.0;
        while (gridIOffset <(size[1]-11.18734)) {
            //  exposedText = "<rect style=\"fill:#f4f4f4;fill-opacity:0.15384617;stroke:none;stroke-width:1.16297209;stroke-opacity:0.61538463\" id=\"rect5982\" width=\""+ (size[0] + 7.584706 + 36.620815) +"\" height=\"10\" x=\""+position[0]+"\" y=\""+ (position[1] + gridIOffset )+ "\" />";//424.45135\" "+size[1]+

            exposedText += "<text\n" +
                    "         style=\"font-style:normal;font-variant:normal;font-weight:normal;font-stretch:normal;font-size:5.70164156px;font-family:'Times New Roman';fill:#767676;fill-opacity:1;stroke-width:0.53452885\"\n" +
                    "       x=\""+(position[0]-30.0)+"\"\n" +
                    "       y=\""+(position[1] + gridIOffset )+"\"\n" +
                    "       id=\"text107-2-1-6\"\n" +
                    "       transform=\"scale(0.99827986,1.0017231)\">IT-1"+gridIOffset+"31</tspan></text>";
            gridIOffset = gridIOffset + 10;
        }

        return exposedText;
    }

}
