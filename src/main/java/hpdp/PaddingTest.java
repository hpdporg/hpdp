package hpdp;

import hpdp.forms.Header;

public class PaddingTest {


    public PaddingTest(){

    }

    public void buildHTMLPage(){
        HPDP hpdp = new HPDP();
        Trans trans = hpdp.getTrans();
        Scraper scraper = hpdp.getScraper();

        scraper.filePath("C:\\Users\\lewis\\hpdp\\DataStore1.csv");
        trans.filePath("C:\\Users\\lewis\\hpdp\\HTML3.html");
        trans.exposureLocation(Trans.ExposureLocation.HTML_FILE);
        HTML html = trans.newHTML();
        Layout layout1 = html.getLayout(0);

        Region region1 = layout1.getSpaceRegion(0);
        Header header1 = new Header();
        header1.headerLevel = Header.HeaderLevel.LVL_1;

        header1.letters = "Padding header letters";


        layout1.newSpaceTopology(header1,region1);

        trans.expose();

    }



}
