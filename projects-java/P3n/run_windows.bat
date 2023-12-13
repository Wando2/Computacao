@echo off

rem Set the path to your Java installation
set JAVA_HOME=C:\path\to\your\java\installation

rem Set the classpath and program directory
set CLASSPATH=C:\path\to\your\program\directory

rem Set any additional JVM options if needed
set JVM_OPTIONS=-XX:+ShowCodeDetailsInExceptionMessages

rem Run the Java program
"%JAVA_HOME%\bin\java" %JVM_OPTIONS% -cp "%CLASSPATH%" lp2g25.P3n25
