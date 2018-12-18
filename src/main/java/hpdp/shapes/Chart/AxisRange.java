package hpdp.shapes.Chart;

import hpdp.Topology;
import java.util.ArrayList;
import java.util.List;

public class AxisRange extends Topology {

    public int[] axisRangeDirection;
    public List<String> rangeValues = null;
    public List<Double> rangeQuantities = null;
    public int rangeValueBasisIndex;
    public double quantityIncrement = 0.0;


    public AxisRange() {

        super();
        axisRangeDirection = new int[3];
        rangeValueBasisIndex = 0;
    }

    public void defineRangeValues(List<String[]> rangeValuesUnfiltered){
        rangeValues = new ArrayList<>();
        String lastRangeValueKey = "";
        for (String[] rangeValue : rangeValuesUnfiltered){

            if (!rangeValue[rangeValueBasisIndex].equals(lastRangeValueKey)) {
                rangeValues.add(rangeValue[rangeValueBasisIndex]);
            }
            lastRangeValueKey = rangeValue[rangeValueBasisIndex];
        }

    }

    public void defineRangeQuantities(){
        rangeQuantities = new ArrayList<>();
        Double quantity = new Double("0.0");
        double quantityValue = 0.0;

        if (axisRangeDirection[0] == 1){
            quantityIncrement =  (double)((size[0]) / rangeValues.size());
        }
        else if(axisRangeDirection[1] == 1){
            quantityIncrement =  (double)(((size[1] - 11.18734)) / rangeValues.size());
        }

        System.out.println("SIZE: " + size[1]);
        System.out.println("Range values size: " + rangeValues.size());

        for (String rangeValue : rangeValues){
            quantity = new Double(quantityValue);
            rangeQuantities.add(quantity);
            System.out.println("QU: " + quantity);
            quantityValue = quantityValue + quantityIncrement;
        }

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



            gridIOffset = 0.0;

            for (String rangeValue :rangeValues ) {

                    if (gridIOffset < (size[1] - 11.18734)) {
                        //  exposedText = "<rect style=\"fill:#f4f4f4;fill-opacity:0.15384617;stroke:none;stroke-width:1.16297209;stroke-opacity:0.61538463\" id=\"rect5982\" width=\""+ (size[0] + 7.584706 + 36.620815) +"\" height=\"10\" x=\""+position[0]+"\" y=\""+ (position[1] + gridIOffset )+ "\" />";//424.45135\" "+size[1]+

                        exposedText += "<text\n" +
                                "         style=\"font-style:normal;font-variant:normal;font-weight:normal;font-stretch:normal;font-size:5.70164156px;font-family:'Times New Roman';fill:#767676;fill-opacity:1;stroke-width:0.53452885\"\n" +
                                "       x=\"" + (position[0] - 30.0) + "\"\n" +
                                "       y=\"" + (position[1] + gridIOffset) + "\"\n" +
                                "       id=\"text107-2-1-6\"\n" +
                                "       transform=\"scale(0.99827986,1.0017231)\">" + rangeValue + "</tspan></text>";
                    System.out.println("Axis range: " + (position[1]+gridIOffset));
                        gridIOffset = gridIOffset + quantityIncrement;


                    }

            }
        }

        return exposedText;
    }


}
