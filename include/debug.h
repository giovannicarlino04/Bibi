#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

enum LogLevel {
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR
};

class Debug {
public:
    static void log(const std::string& message, LogLevel level = LOG_INFO) {
        std::string prefix;
        switch (level) {
            case LOG_INFO:
                prefix = "[INFO] ";
                break;
            case LOG_WARN:
                prefix = "[WARN] ";
                break;
            case LOG_ERROR:
                prefix = "[ERROR] ";
                break;
        }

        std::string logMessage = prefix + message;

        // Print to console
        std::cout << logMessage << std::endl;

        // Optionally, log to a file
        if (logFile.is_open()) {
            logFile << logMessage << std::endl;
        }
    }

    static void setLogFile(const std::string& filename) {
        if (logFile.is_open()) {
            logFile.close();
        }
        logFile.open(filename, std::ios::out | std::ios::app);
    }

    static void closeLogFile() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

private:
    static std::ofstream logFile;
};

std::ofstream Debug::logFile;

#endif
