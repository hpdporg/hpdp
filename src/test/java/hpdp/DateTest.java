package hpdp;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

import org.junit.jupiter.api.*;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvFileSource;

import java.util.Calendar;


public class DateTest {



    /**
     * Tests from the "Date" sub-suite.
     */
    @Nested
    public class DateTests {

        @Test
        @DisplayName("Builds a date from a String")
        @Tag("Unit")
        public void buildsDateFromString() {
            String initial = "2019-04-02";
            System.out.println("Initial: " + initial);
            Time time = new Time();
            String parsedYear = initial.substring(0, 4);
            String parsedMonth = initial.substring(5, 7);
            String parsedDay = initial.substring(8, 10);
            System.out.println("Parsed Year: " + parsedYear);
            System.out.println("Parsed Month: " + parsedMonth);
            System.out.println("Parsed Day: " + parsedDay);

            assertEquals("2019", parsedYear);
            assertEquals("04", parsedMonth);
            assertEquals("02", parsedDay);

            time.buildTime(parsedYear, parsedMonth, parsedDay);
            System.out.println("After Year: " + time.year);
            System.out.println("After Month: " + time.month);
            System.out.println("After Day: " + time.day);

            assertEquals(2019, time.year);
            assertEquals(4, time.month);
            assertEquals(2, time.day);

        }
        @Test
        @DisplayName("Gets date String without dashes")
        @Tag("Unit")
        public void getsDateWithoutDashes() {

            long millis=System.currentTimeMillis();
            java.util.Date currDate=new java.util.Date(millis);
            Calendar cal = Calendar.getInstance();
            //System.out.println(cal.get(Calendar.YEAR));

            Time time = new Time();
            time = time.getNow();
            String date = time.getDateStringNoDashes();
            System.out.println("Date no dashes: "+date);
            assertEquals(String.format("%04d",cal.get(Calendar.YEAR)), date.substring(0,4));
            assertEquals(String.format("%02d",(cal.get(Calendar.MONTH)+1)), date.substring(4,6));
            assertEquals(String.format("%02d",cal.get(Calendar.DAY_OF_MONTH)), date.substring(6,8));
        }
    }

}

