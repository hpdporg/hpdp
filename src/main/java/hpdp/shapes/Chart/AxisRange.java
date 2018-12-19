package hpdp.shapes.Chart;

import hpdp.Time;
import hpdp.Topology;
import java.util.ArrayList;
import java.util.List;

public class AxisRange extends Topology {

    public int[] axisRangeDirection;
    public List<String> rangeValues = null;
    public List<Double> rangeQuantities = null;
    public int rangeValueBasisIndex;
    public double quantityIncrement = 0.0;
    public double iQuantityIncrement = 0.0;
    public Time minTime = null;
    public Time maxTime = null;


    public AxisRange() {

        super();
        axisRangeDirection = new int[3];
        rangeValueBasisIndex = 0;
    }

    public void defineRangeValues(List<String[]> rangeValuesUnfiltered){
        //
        rangeValues = new ArrayList<>();
        /*String lastRangeValueKey = "";
        */
        for (String[] rangeValue : rangeValuesUnfiltered){
            rangeValues.add(rangeValue[0]);
        /*    if (!rangeValue[rangeValueBasisIndex].equals(lastRangeValueKey)) {
                rangeValues.add(rangeValue[rangeValueBasisIndex]);
            }
            lastRangeValueKey = rangeValue[rangeValueBasisIndex];*/
        }

    }

    public void defineRangeQuantities(){
        rangeQuantities = new ArrayList<>();
        Double quantity = new Double("0.0");
        double quantityValue = 0.0;

        if (axisRangeDirection[0] == 1){
            quantityIncrement =  (double)((size[0]) / 10.0);
            //624.45135, 0.5 increment
            long timestampRange = maxTime.timestamp-minTime.timestamp;
            double coordinateRange = size[0];
            double ratio = 0.5 / coordinateRange;
            iQuantityIncrement = ratio * (double) timestampRange;
            iQuantityIncrement = 0.5;

        }
        else if(axisRangeDirection[1] == 1){
            quantityIncrement =  (double)(((size[1] - 11.18734)) / rangeValues.size());

            //System.out.println("SIZE: " + size[1]);
            //System.out.println("Range values size: " + rangeValues.size());

            for (String rangeValue : rangeValues){
                quantity = new Double(quantityValue);
                rangeQuantities.add(quantity);
                //System.out.println("QU: " + quantity);
                quantityValue = quantityValue + quantityIncrement;
            }
        }



    }

    // i Coordinate from Timestamp
    public double iFromTimestamp(long timestamp){

        long timestampRange = maxTime.timestamp-minTime.timestamp;
        double coordinateRange = size[0];
        double coordinateI = 0.0;
        double increment = ((double)(timestamp-minTime.timestamp)/timestampRange);
        coordinateI = coordinateRange * increment;



        return coordinateI;
    }

    public void setMinTime(Time time){
        this.minTime = time;
    }

    public void setMaxTime(Time time){
        this.maxTime = time;
    }

    public int getRangeValueIndex(String value){
        int index = 0;
        for (String rangeValue : rangeValues){
            if (rangeValue.equals(value)){
                break;
            }
            ++index;
        }
        return index;
    }


    @Override
    public String expose(){
        if (axisRangeDirection[1] == 1) {
            double gridIOffset = 0.0;

            double iDisplacement = 30.0;

            gridIOffset = 0.0;

            for (String rangeValue :rangeValues ) {

                    if (gridIOffset < (size[1] - 11.18734)) {
                        //  exposedText = "<rect style=\"fill:#f4f4f4;fill-opacity:0.15384617;stroke:none;stroke-width:1.16297209;stroke-opacity:0.61538463\" id=\"rect5982\" width=\""+ (size[0] + 7.584706 + 36.620815) +"\" height=\"10\" x=\""+position[0]+"\" y=\""+ (position[1] + gridIOffset )+ "\" />";//424.45135\" "+size[1]+


                        exposedText +="<a xlink:href=\"https://prodqtest.us.aegon.com/p/3/portal/project#tab=testdesign&object=1&id="+rangeValue+"\"\n" +
                                "\t  target=\"_blank\">";
                        exposedText += "<text\n" +
                                "         style=\"font-style:normal;font-variant:normal;font-weight:normal;font-stretch:normal;font-size:5.70164156px;font-family:'Times New Roman';fill:#767676;fill-opacity:1;stroke-width:0.53452885\"\n" +
                                "       x=\"" + (position[0] - iDisplacement) + "\"\n" +
                                "       y=\"" + (position[1] + gridIOffset) + "\"\n" +
                                "       id=\"text107-2-1-6\"\n" +
                                "       transform=\"scale(0.99827986,1.0017231)\">" + rangeValue + "</text>";
                        exposedText += "</a>";

                        gridIOffset = gridIOffset + quantityIncrement;


                    }

            }
            exposedText += "<text\n" +
                    "       style=\"font-style:normal;font-variant:normal;font-weight:normal;font-stretch:normal;font-size:11.12705088px;font-family:'Times New Roman';fill:#767676;fill-opacity:1;stroke-width:0.53452885\"\n" +
                    "       x=\""+(position[0] - 10.0-iDisplacement)+"\"" +
                    "       y=\""+((size[1]/2.0)+position[1])+"\"" +
                    "       id=\"text107-2\"" +
                    " transform=\"rotate(-90,"+(position[0] - 10.0-iDisplacement)+" ,"+((size[1]/2.0)+position[1])+")\" "+
//                    "       transform=\"matrix(-0.00827111,-1.0016888,0.99824552,-0.00829964,0,0)\""+
                    "         >Coverage</text>";

        }

        return exposedText;
    }



}
