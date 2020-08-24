cd src
dir /s /B *.java > sources.txt
javac -cp ../external/junit-platform-console-standalone-1.1.0.jar;../src/main/java/hpdp;../src\main\java\hpdp;../src/test/resources;../src/test/java/hpdp;../src/main/java/hpdp/storage @sources.txt ^
 && cd ..
