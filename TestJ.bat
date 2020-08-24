cd src/test/java
rmdir /S /Q ..\..\..\report\junit
java -jar ../../../external/junit-platform-console-standalone-1.1.0.jar --reports-dir ../../../report/junit --cp hpdp;../../main/java;../resources;.;./hpdp --select-package hpdp
cd ../../../