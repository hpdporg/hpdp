package hpdp.forms;

import hpdp.Region;

import java.util.List;
import java.util.ArrayList;

public class Header extends Region{


    public enum HeaderLevel{
        LVL_1,LVL_2
    }

    public HeaderLevel headerLevel;

    public Header(){

        super();
        this.headerLevel = HeaderLevel.LVL_1;
        this.exposedText = "";
        this.region = false;


    }





    @Override
    public String expose(){


        if (headerLevel.equals(HeaderLevel.LVL_1)) {
            size[0] = 424.45135;
            size[1] = 36.183823;
            super.expose();
            //position[0] = getTopologyRegion(this).getPosition()[0];

            exposedText = "<rect style=\"fill:#f4f4f4;fill-opacity:0.15384617;stroke:none;stroke-width:1.16297209;stroke-opacity:0.61538463\" id=\"rect5982\" width=\"100%\" x=\""+position[0]+"\" y=\""+position[1]+"\" />";//424.45135\" "+size[1]+
            exposedText += "<text\n" +
                    " style=\"fill:#4e4e4e;fill-opacity:0.85882353;stroke:none;stroke-width:0.53452885;font-style:normal;font-weight:normal;font-size:21.38115501px;line-height:1.25;font-family:\"Times New Roman\";letter-spacing:0px;word-spacing:0px\"\n" +
                    "  x=\"7.9435277\"\n" +
                    "  y=\"20.0\"" +
                    "  id=\"text99\"\n" +
                    "   transform=\"scale(0.99827982,1.0017231)\">"+letters+"</text>";
        }
        else if(headerLevel.equals(HeaderLevel.LVL_2)){
            size[0] = 422.49805;
            size[1] = 28.112316;
            super.expose();
           // position[0] = getTopologyRegion(this).getPosition()[0];
            exposedText += "<defs>" +
                /*    "     id=\"defs2\"><linearGradient\n" +
                    "       xlink:href=\"#linearGradient8957\"\n" +
                    "       id=\"linearGradient8959\"\n" +
                    "       x1=\"241.132\"\n" +
                    "       y1=\"67.0\"\n" +
                    "       x2=\"241.132\"\n" +
                    "       y2=\"38.0\"\n" +
                    //"       gradientTransform=\"matrix(0.99539799,0,0,1.0000329,0.00302448,0.01772718)\" " +
                    "/><stop\n" +
                    "         style=\"stop-color:#e2e2e2;stop-opacity:1;\"\n" +
                    "         offset=\"0\"\n" +
                    "         id=\"stop8953\" />\n" +
                    "      <stop\n" +
                    "         style=\"stop-color:#e2e2e2;stop-opacity:0;\"\n" +
                    "         offset=\"1\"\n" +
                    "         id=\"stop8955\" />\n" +
                    "    </linearGradient><linearGradient\n" +
                    "       id=\"linearGradient8957\">\n" +
                    "      <stop\n" +
                    "         style=\"stop-color:#e2e2e2;stop-opacity:1;\"\n" +
                    "         offset=\"0\"\n" +
                    "         id=\"stop8953\" />\n" +
                    "      <stop\n" +
                    "         style=\"stop-color:#e2e2e2;stop-opacity:0;\"\n" +
                    "         offset=\"1\"\n" +
                    "         id=\"stop8955\" />\n" +
                    "    </linearGradient>" +
                    */
                    " <linearGradient " +
                    " id=\"linearGradient8959\" " +
                             "       x1=\"0%\"" +
                    "       y1=\"0%\"" +
                    "       x2=\"0%\"" +
                    "       y2=\"100%\"" +
                 /*  "       x1=\"241.132\"" +
                    "       y1=\"48.0\"" +
                    "       x2=\"241.132\"" +
                    "       y2=\"38.0\"" +*/
                    ">" +
                    "   <stop offset=\"0%\" stop-color=\"#e2e2e2\" stop-opacity=\"0\"/>" +
                    "   <stop offset=\"100%\" stop-color=\"#e2e2e2\" stop-opacity=\"1\"/>" +
                    "    </linearGradient>" +
                    "</defs>";

            exposedText += "<rect\n" +

//                    "       style=\"fill:url(#linearGradient8959);fill-opacity:1;stroke:#a8a8a8;stroke-width:0.40312913;stroke-opacity:0.61538463\"\n" +
                    "       id=\"rect5980\"\n" +
                    " style=\"fill:url(#linearGradient8959);fill-opacity:1;stroke:#a8a8a8;stroke-width:0.40312913;stroke-opacity:0.61538463\""+
                    "       width=\"100%\""+//+size[0]+"\"\n" +
                    "       height=\""+size[1]+"\"" +
                    "       x=\""+position[0]+"\"" +
                    "       y=\""+position[1]+"\"/>";

            exposedText += "<text\n" +
                    "       style=\"fill:#4e4e4e;fill-opacity:1;stroke-width:0.42110854;font-style:normal;font-weight:normal;font-size:16.84434319px;line-height:1.25;font-family:\"Times New Roman\";letter-spacing:0px;word-spacing:0px;fill:#4e4e4e;fill-opacity:1;stroke:none;stroke-width:0.42110854\"\n" +
                    "       x=\""+(position[0]+23.846361)+"\"\n" +
                    "       y=\""+(position[1]+20)+"\"\n" +
                    "       id=\"text103\"" +
                    "       transform=\"scale(0.98683003,1.0133457)527\">"+letters+"</text>\n" +
                    " ";
        }
        return exposedText;
    }


}
