# Heavy PortAudio example

This is an example integration project showing how to open an audio file using libsndfile, process it through a Heavy patch and send it to the output via PortAudio 
 
### Dependencies

* libsndfile http://www.mega-nerd.com/libsndfile/
* PortAudio v19 http://portaudio.com

Note: make sure your header/library search paths to the libraries are correct. The xcode project assumes they are installed via Homebrew

```
$ brew install portaudio
$ brew install libsndfile
```


Sample courtesy of Robinhood76 https://www.freesound.org/people/Robinhood76/sounds/134762/