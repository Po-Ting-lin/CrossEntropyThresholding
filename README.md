Welcome to collaborate and optimize this repo!

## Introduction
Implementation of 2D cross-entropy threshold based on GLCM, which refers to the paper[1]. This method is capable of achieving better results when compared with 1D
cross-entropy and other classical GLCM based thresholding methods. However, this algorithm has a higher time complexity than the other thresholding algorithms. 
To enhance the performance, AVX and openmp are used. In the test sample, the elapsed time is 53 ms, which is roughly 12 times faster than the naive method (618 ms).

### Requirements
* C++ STL
* OpenCV 4.2.0
* OpenMp
* AVX instruction set

## References

```
[1] Nie, Fangyan, et al. 
    "Two-dimensional minimum local cross-entropy thresholding based on co-occurrence matrix."
    Computers & Electrical Engineering 37.5 (2011): 757-767.
```

## Test
* test image  
![](/EntropyThresholding/test.png)

* result    
![](/EntropyThresholding/result.png)
