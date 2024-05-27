#include<temp.h>
//#include<image_1.h>
//#include<image_2.h>
//#include<image_3.h>
//#include<image_4.h>
//#include<image_5.h>
//#include<image_6.h>
//#include<image_7.h>
//#include<image_8.h>
//#include<image_9.h>
//#include<image_10.h>


#define STAR_MIN_PIXEL 9
#define STAR_MAX_PIXEL 150
#define MAX_STARS 5
#define SKIP_PIXELS 3
#define PIXEL_WIDTH 0.0000022
int threshold;

int currState = HIGH;
int prevState = HIGH;
int button = 19;




//char arr_out_img_1[BREADTH + 2][LENGTH + 2] = {
//    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//    {0,1,1,2,1,1,1,1,2,1,1,2,1,1,0,1,1,1,1,1,1,1,1,1,2,1,1,1,2,1,1,0},
//    {0,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,2,1,1,0},
//    {0,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
//    {0,1,2,1,1,1,2,2,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,2,1,2,2,1,1,1,0},
//    {0,1,1,1,1,1,1,1,2,1,1,2,1,1,2,1,2,1,1,1,1,2,1,1,1,1,2,1,1,1,2,0},
//    {0,1,1,1,1,1,2,2,1,1,2,1,1,2,2,1,1,1,1,2,1,2,1,2,1,1,2,2,1,1,1,0},
//    {0,1,1,1,1,1,1,1,2,1,2,1,2,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,2,1,0},
//    {0,1,1,1,2,1,1,2,2,1,2,1,2,1,2,2,1,1,1,1,2,2,1,2,1,1,1,1,1,1,1,0},
//    {0,1,1,1,2,1,1,2,1,1,2,2,1,2,1,0,1,1,1,1,1,1,1,2,1,2,1,1,1,2,1,0},
//    {0,1,1,1,1,2,1,1,2,1,2,1,2,2,1,1,1,1,1,1,2,2,2,1,1,1,2,2,1,2,1,0},
//    {0,2,1,2,1,1,1,1,1,1,1,2,3,4,1,1,1,1,0,1,1,1,2,1,2,1,1,1,1,1,2,0},
//    {0,1,2,1,1,1,2,1,1,1,1,4,19,23,3,1,1,1,2,1,1,1,2,1,1,1,2,2,1,1,1,0},
//    {0,1,1,1,2,2,1,2,1,1,1,2,20,24,5,1,1,1,1,1,1,2,1,1,2,1,1,2,1,1,1,0},
//    {0,1,1,2,1,2,1,1,1,1,2,2,4,4,2,1,1,1,1,1,1,1,1,2,1,2,2,1,1,1,2,0},
//    {0,1,1,1,2,1,1,1,1,2,1,1,1,1,2,1,2,1,1,1,1,2,1,1,1,1,2,1,2,1,1,0},
//    {0,1,2,1,1,1,1,1,1,1,2,1,2,1,1,2,1,2,1,1,2,1,1,1,1,2,2,1,2,1,0,0},
//    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,2,1,2,1,1,1,1,1,1,1,2,1,0},
//    {0,2,1,1,1,1,1,2,1,1,1,1,1,1,1,2,2,1,2,2,2,1,1,1,1,1,1,1,1,1,1,0},
//    {0,1,1,1,1,0,1,1,1,1,1,1,1,1,2,1,1,2,1,2,1,1,1,2,1,1,1,1,2,1,1,0},
//    {0,1,1,2,1,2,1,2,1,1,1,1,2,1,1,1,0,2,1,1,1,1,1,1,1,2,2,1,1,1,1,0},
//    {0,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,2,2,1,1,1,2,1,1,1,1,2,1,1,0},
//    {0,1,1,1,1,1,1,1,1,1,1,2,1,2,2,1,1,2,1,1,1,2,1,1,1,2,1,1,2,2,1,0},
//    {0,1,2,1,1,1,1,1,2,1,2,1,1,2,1,2,1,2,1,1,1,2,1,1,2,1,1,2,1,2,1,0},
//    {0,1,2,1,1,1,1,1,1,1,1,1,2,1,2,2,2,2,1,2,2,1,1,2,2,1,1,1,1,1,1,0},
//    {0,1,1,1,1,1,1,2,1,0,1,1,1,2,1,1,1,2,2,1,2,1,1,1,2,0,1,1,2,1,1,0},
//    {0,2,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,2,1,1,0},
//    {0,1,2,1,1,1,2,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,2,0},
//    {0,2,1,2,1,2,2,1,2,1,1,1,2,1,1,1,2,1,2,1,2,1,1,1,1,1,1,1,2,1,1,0},
//    {0,1,1,1,2,1,1,2,1,1,1,1,1,1,1,2,1,1,1,1,2,1,1,1,1,1,2,2,1,1,2,0},
//    {0,2,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0},
//    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
//};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  currState = digitalRead(button);
   if(currState != prevState)
   {
      // A transition occurred
      if(currState == LOW)
      {
         // Switch is now pressed
         RGA(arr_out_img);
//         Serial.println("\n");
      }
      else
      {
          // Switch is now released
      }
   }
   prevState = currState;

   
}

void getData(int p_i, int p_j, unsigned int* star_num, double x_sum[], double y_sum[], double pixel_sum[], int num_pixels[], char arr_out_img[BREADTH + 2][LENGTH + 2]){
    // base case
    if (arr_out_img[p_j][p_i] <= threshold){
        return;
    }

    // keeping track of the sums
    x_sum[*star_num] += arr_out_img[p_j][p_i] * p_i;
    y_sum[*star_num] += arr_out_img[p_j][p_i] * p_j;
    pixel_sum[*star_num] += arr_out_img[p_j][p_i];
    num_pixels[*star_num] += 1;

    arr_out_img[p_j][p_i] = 0;

    // recursive calls
    getData(p_i - 1, p_j, star_num, x_sum, y_sum, pixel_sum, num_pixels, arr_out_img);
    getData(p_i + 1, p_j, star_num, x_sum, y_sum, pixel_sum, num_pixels, arr_out_img);
    getData(p_i, p_j - 1, star_num, x_sum, y_sum, pixel_sum, num_pixels, arr_out_img);
    getData(p_i, p_j + 1, star_num, x_sum, y_sum, pixel_sum, num_pixels, arr_out_img);

    return;
}



void regionGrowth(char arr_out_img[BREADTH + 2][LENGTH + 2], double centroids_st[MAX_STARS][3], char* tot_stars)
{
    unsigned int valid_stars = 0;
    unsigned int star_num = 0;
    double x_sum[MAX_STARS] = {0};
    double y_sum[MAX_STARS] = {0};
    double pixel_sum[MAX_STARS] = {0};
    int num_pixels[MAX_STARS] = {0};

    for (unsigned int j = 1; j < BREADTH + 1; j += SKIP_PIXELS){
        for (unsigned int i = 1; i < LENGTH + 1; i += SKIP_PIXELS){
            if (arr_out_img[j][i] > threshold)
            {
              getData(i, j, &star_num, x_sum, y_sum, pixel_sum, num_pixels, arr_out_img);
              star_num++;
            }
        }
    }

    for (unsigned int k = 0; k < star_num; k++)
    {   
        if ((num_pixels[k] <= STAR_MAX_PIXEL) & (num_pixels[k] > STAR_MIN_PIXEL))
        {
            valid_stars++;
            centroids_st[valid_stars-1][0] = valid_stars;
            centroids_st[valid_stars-1][1] = (x_sum[k] / pixel_sum[k] - ((LENGTH / 2) + 0.5)) * PIXEL_WIDTH;
            centroids_st[valid_stars-1][2] = (-1 * (y_sum[k] / pixel_sum[k] - ((BREADTH / 2.0) + 0.5))) * PIXEL_WIDTH;
        }
    }
    
    *tot_stars += valid_stars;
    
    return;
}

void RGA(char arr_out_img[BREADTH + 2][LENGTH + 2]){
long int t_start = micros();
    unsigned long sum = 0;
  for(int i = 0; i < BREADTH + 2; i++){
    for(int j = 0; j < LENGTH + 2; j++){
      sum = sum + arr_out_img[i][j];
    }
  }

  int mean = sum/(LENGTH*BREADTH);
  unsigned long variance = 0;

  for(unsigned int i = 0; i < BREADTH + 2; i++){
    for(unsigned int j = 0; j < LENGTH + 2; j++){
      variance = variance + ((arr_out_img[i][j] - mean)*(arr_out_img[i][j] - mean));
    }
  }
  int std = sqrt(variance/(LENGTH*BREADTH));
  threshold = mean + 5*std;
threshold = 7;
  
    char tot_stars = 0;
    double centroids_st[MAX_STARS][3];

    // Perform Feature Extraction
    regionGrowth(arr_out_img, centroids_st, &tot_stars);
    
   long int t_end = micros();
   Serial.println(threshold);
   Serial.println(t_end - t_start);
    // Print FE output on the terminal  
    for(int i = 0; i < tot_stars; i++){
        Serial.println(centroids_st[i][0]);
        Serial.println(centroids_st[i][1], 15);
        Serial.println(centroids_st[i][2], 15);
    }
      return;
}
