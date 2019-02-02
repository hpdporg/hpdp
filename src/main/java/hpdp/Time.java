package hpdp;

import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Calendar;
import java.util.Date;
import java.util.TimeZone;

public class Time {

    public long year;
    public long month;
    public long day;
    public long hour;
    public long minute;
    public long second;
    public long ms;
    public long timestamp;


    public Time(){
        year = 0;
        month = 0;
        day = 0;
        hour = 0;
        minute = 0;
        second = 0;
        ms = 0;
        timestamp = 0;
    }

    public Time getNow(){
        Time time = new Time();


    /*    Date date = new Date();
        LocalDateTime dateTime = LocalDateTime.parse(date.toString(), DateTimeFormatter.ofPattern("EEE MMM dd kk:mm:ss zzz uuuu"));
        dateTime.format(DateTimeFormatter.ofPattern("uuuu-LL-dd"));
        String dateStr = dateTime.toString().substring(0, 10); 				// e.g. 2018-11-02T17:03:03 needs Time removed with substring
        */
        Calendar calendar = Calendar.getInstance(TimeZone.getTimeZone("GMT"));
        time.timestamp = calendar.getTimeInMillis();
        time.year = calendar.get(Calendar.YEAR);
        time.month = calendar.get(Calendar.MONTH) - 1;
        time.day = calendar.get(Calendar.DAY_OF_MONTH);
        time.hour = calendar.get(Calendar.HOUR_OF_DAY);
        time.minute = calendar.get(Calendar.MINUTE);
        time.second = calendar.get(Calendar.SECOND);
        time.ms = calendar.get(Calendar.MILLISECOND);


        return time;
    }

    public static Time timeFromTimestamp(long timestamp){
        Time time = new Time();

        Calendar calendar = Calendar.getInstance(TimeZone.getTimeZone("GMT"));
        calendar.setTimeInMillis(timestamp);
        time.timestamp = timestamp;
        time.year = calendar.get(Calendar.YEAR);
        time.month = calendar.get(Calendar.MONTH) + 1;
        time.day = calendar.get(Calendar.DAY_OF_MONTH);
        time.hour = calendar.get(Calendar.HOUR_OF_DAY);
        time.minute = calendar.get(Calendar.MINUTE);
        time.second = calendar.get(Calendar.SECOND);
        time.ms = calendar.get(Calendar.MILLISECOND);

        return time;
    }

    public static long timestampFromTime(Time time){

        return time.timestamp;
    }

    public String toString(){
        return year + " " + month + " " +day + " " +hour + " "+ " " +minute + " " + second + " " + ms + " " + timestamp;
    }

    public String getDateString(){
        String dateString = year+"-"+month+"-"+day;
        return dateString.replace("--", "-"); // Two dashes are showing after the year. Find a different fix upstream


    }
    public String getDateTimeString(){
        NumberFormat formatter = new DecimalFormat("00");
        NumberFormat yearFormatter = new DecimalFormat("0000");
        String dateTimeString = yearFormatter.format(year)+"-"+formatter.format(month)+"-"+formatter.format(day)+" "+formatter.format(hour)+":"+formatter.format(minute);
        return dateTimeString.replace("--", "-"); // Two dashes are showing after the year. Find a different fix upstream

    }



}
