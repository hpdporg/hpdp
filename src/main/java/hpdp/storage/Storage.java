package hpdp.storage;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;
import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.File;


public class Storage{

    BufferedWriter file;
    BufferedReader fileReader;
    public String filePath = null;
    public boolean read = false;

    public Storage(){
        filePath = null;


    }

    public Storage newFile(String filePath) throws IOException{



        if (read) {
            fileReader = new BufferedReader(new FileReader(filePath));
        }
        else{
            File existingFile = new File(filePath);
            existingFile.delete();
            file = new BufferedWriter(new FileWriter(filePath));
        }


        return this;
    }



    public void writeHTML(String htmlText) throws IOException {
        if (file != null){

            file.write(htmlText);
            file.flush();
        }

    }

    public String readLine() throws IOException {
        if (fileReader != null){
            return fileReader.readLine();
        }
        return null;
    }

    public void setRead(boolean read){
        this.read = read;
    }


}
