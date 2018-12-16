package hpdp.storage;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.File;


public class Storage{

    BufferedWriter file;
    public String filePath = null;

    public Storage(){
        filePath = null;


    }

    public Storage newFile(String filePath) throws IOException{

        File existingFile = new File(filePath);
        existingFile.delete();
        file = new BufferedWriter(new FileWriter(filePath));


        return this;
    }

    public void writeHTML(String htmlText) throws IOException {
        if (file != null){

            file.write(htmlText);
            file.flush();
        }

    }


}
