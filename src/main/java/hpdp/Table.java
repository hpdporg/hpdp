package hpdp;

import java.util.ArrayList;
import java.util.List;

public class Table {

    protected int rowCount;
    protected int columnCount;

    protected List<List> rows;


    public Table(){
        rows = new ArrayList<>();
        rowCount = 0;
        columnCount = 0;
    }

    public void newRow(String... values){
        List<String> newRow = new ArrayList<>();
        for (String value : values){
            newRow.add(value);
        }
        rows.add(newRow);
        if (newRow.size() > columnCount){                       // Some new rows may not fill each column.
            columnCount = newRow.size();
        }
        rowCount = rows.size();
    }

    public int getRowCount(){
        return rowCount;
    }

    public int getColumnCount(){
        return columnCount;
    }

    public List<List> getRows(){
        return rows;
    }



}
