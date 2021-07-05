#include "xcLogger.h"

namespace xcEngineSDK {

  void 
  Logger::saveError(String& error, String& fileOfError) {

    OFstream errorFile("Error.txt");
    if (errorFile.is_open()) {
      errorFile << fileOfError + ", " + error << "\n";
      errorFile.close();
    }

  }

}
