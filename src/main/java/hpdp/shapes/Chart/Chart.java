package hpdp.shapes.Chart;

import hpdp.Region;
import hpdp.Topology;
import java.util.List;
import java.util.ArrayList;

public class Chart  extends Region {

    public Area area = null;
    public AxisRange iAxisLabel = null;
    public  AxisRange jAxisLabel = null;
    public List<Trace> traces = null;



    public Chart(){
        super();
        this.region = false;
        topologies = new ArrayList<>();

        area = new Area();
        iAxisLabel = new AxisRange();
        iAxisLabel.axisRangeDirection[0] = 1;
        jAxisLabel = new AxisRange();
        jAxisLabel.axisRangeDirection[1] = 1;

        traces = new ArrayList<>();

        topologies.add(area);
        topologies.add(iAxisLabel);
        topologies.add(jAxisLabel);


    }

    public void newTrace(Trace trace){
        topologies.add(trace);
        traces.add(trace);
    }


}
