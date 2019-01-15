package hpdp.shapes.Chart;

import hpdp.Region;
import hpdp.Topology;
import java.util.List;
import java.util.ArrayList;
import hpdp.shapes.Chart.Legend.LegendStyle;

public class Chart  extends Region {

    public Area area = null;
    public AxisRange iAxisLabel = null;
    public  AxisRange jAxisLabel = null;
    public List<Trace> traces = null;
    public Legend legend = null;


    public Chart(){
        super();
        this.region = false;
        topologies = new ArrayList<>();

        area = new Area();
        iAxisLabel = new AxisRange();
        iAxisLabel.axisRangeDirection[0] = 1;
        jAxisLabel = new AxisRange();
        jAxisLabel.axisRangeDirection[1] = 1;
        legend = new Legend();
        legend.legendStyle = LegendStyle.GRAPH;

        traces = new ArrayList<>();

        topologies.add(area);
        topologies.add(iAxisLabel);
        topologies.add(jAxisLabel);
        topologies.add(legend);


    }


    public Chart(boolean hasAxisLabels){
        super();

        this.region = false;
        topologies = new ArrayList<>();

        area = new Area();
        if (hasAxisLabels) {
            iAxisLabel = new AxisRange();
            iAxisLabel.axisRangeDirection[0] = 1;
            jAxisLabel = new AxisRange();
            jAxisLabel.axisRangeDirection[1] = 1;
        }
        legend = new Legend();

        if (hasAxisLabels){
            legend.legendStyle = LegendStyle.GRAPH;
        }
        else{
            legend.legendStyle = LegendStyle.COLOR_INDICATOR;
        }

        traces = new ArrayList<>();

        topologies.add(area);
        if (hasAxisLabels) {
            topologies.add(iAxisLabel);
            topologies.add(jAxisLabel);
        }
        topologies.add(legend);


    }

    public void newTrace(Trace trace){
        topologies.add(trace);
        traces.add(trace);
    }


}
