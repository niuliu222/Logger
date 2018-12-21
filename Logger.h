#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
namespace LLD{
    namespace Log{
		enum LogType {
			Message,
			Warning,
			Error,
		};
		class Logger {
		public:
			void SetOutputFile(const std::string & str) {
				OutputUrl = str;
				Output.open(str, ios::out, 0);
			}
			void SetStdOutputEnable(bool enable) {
				this->EnableStdOutput = enable;
			}
			void Log(const std::string & str, LogType type) {
				std::string flog = FormatLog(str, type);
				Output << flog << std::endl;
				if (EnableStdOutput) {
					std::cout << flog << std::endl;
				}
			}
			~LogType() {
				Output.close();
			}
		protected:
			const char *MapLogType(LogType type) {
				switch (type)
				{
				case LLD::Log::Message:
					return "Message";
				case LLD::Log::Warning:
					return "Warning";
				case LLD::Log::Error:
					return "Error";
				default:
					return "Unknow";
				}
			}

			std::string FormatLog(const std::string str, LogType type) {
				const char * ptr = MapLogType(type);
				std::ostringstream ss;
				ss << "[" << ptr << "]:" << str;

				return ss.str();
			}
		private:
			std::string OutputUrl;
			std::ofstream Output;
			bool EnableStdOutput;
		};


		std::shared_ptr<Logger> logger;

        void SetOutputFile(const std::string& str){
			logger->SetOutputFile(str);
        }

		void SetStdOutput(bool enable = true) {
			logger->SetStdOutputEnable(enable);
		}

		void LogMessage(const std::string & str, const char * file, int line) {
			logger->Log(str, LogType::Warning);
		}

		void LogWarning(const std::string & str, const char * file, int line){
			logger->Log(str, LogType::Message);
		}

		void LogError(const std::string & str, const char * file, int line) {
			logger->Log(str, LogType:::Error);
		}

		void LogInit(const std::string &url, bool enable_std_output) {
			logger = std::make_shared<Logger>();
			logger->SetOutputFile(url);
			logger->SetStdOutputEnable(enable_std_output);
		}

		void LogInit(const char *url = "./logger.txt", bool enable_std_output = true) {
			std::string str = trl;
			LogInit(str, enable_std_output);
		}

    }
}