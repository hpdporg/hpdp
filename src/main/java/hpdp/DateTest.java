package hpdp;

public class DateTest {



    public void runTest(){
        String initial = "2019-04-02";
        System.out.println("Initial: " + initial);
        Time time = new Time();
        String parsedYear = initial.substring(0,4);
        String parsedMonth = initial.substring(5,7);
        String parsedDay = initial.substring(8,10);
        System.out.println("Parsed Year: "+parsedYear);
        System.out.println("Parsed Month: "+parsedMonth);
        System.out.println("Parsed Day: "+parsedDay);

        time.buildTime(parsedYear,parsedMonth,parsedMonth);
        System.out.println("After Year: "+time.year);
        System.out.println("After Month: "+time.month);
        System.out.println("After Day: "+time.day);


        Time time2 = new Time();
        time2 = time2.getNow();
        String date = time2.getDateStringNoDashes();
        System.out.println("Date no dashes: "+date);
    }
}
