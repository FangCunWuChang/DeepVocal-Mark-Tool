#include "filescaner.h"

FileScaner::FileScaner() : QThread()
{

}

void FileScaner::run()
{
    this->filelist.clear();
    for(int i=0;i<paths.size();i++){
        QDir dir(paths.at(i));
        QStringList files;
        if(dir.exists()){
          dir.setFilter(QDir::Files);
          int count=dir.count();
          for(int j=0;j<count;j++){
              QString name=dir[j];
              if(name.endsWith(".wav",Qt::CaseInsensitive)){
                  if(QWaveInfo::checkwav(paths.at(i)+"/"+name,1,global_sets::FS,16,global_sets::perp*2,global_sets::maxlength)){
                      files.append(name);
                  }

              }
          }
        }
        filelist.append(files);
    }
    emit files(paths,filelist);
}

void FileScaner::setpaths(QStringList paths)
{
    this->paths=paths;
    this->filelist.clear();
}
