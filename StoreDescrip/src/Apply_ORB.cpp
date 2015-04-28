#include "Apply_ORB.h"

Apply_ORB::Apply_ORB()
{
    //ctor
}

int Apply_ORB:: applyORB(std::map<int,std::string> imageList)
{
	int index_to_image=0;
	std::vector<cv::Mat> descriptor;
	for(;index_to_image < imageList.size();index_to_image++)
	{
		cv::Mat image =imread(imageList.at(index_to_image),CV_LOAD_IMAGE_GRAYSCALE);

		if(!image.empty())
		{
			std::vector<KeyPoint> image_keypoints;
			cv::Mat image_descriptor;

			cv::FeatureDetector * orb_kp_detector = new cv::ORB();
			//detect the location/coordinates of the keypoints in image
			orb_kp_detector->detect(image, image_keypoints);

			//pushing image_keypoints to all_keypoints
			all_keypoints.push_back(image_keypoints);

			cv::DescriptorExtractor * orb_kp_descriptor = new cv::ORB();
			//extract the descriptors from images
			orb_kp_descriptor->compute(image, image_keypoints, image_descriptor);

			//pushing image_descriptors to all_decriptors
			all_descriptors.push_back(image_descriptor);
		}

	}

	return 1;

}

std::vector<cv::Mat> Apply_ORB:: getAllImageFeatureDescriptors()
{
	if(all_descriptors.empty())
	{
		//exit with some status
	}
	return all_descriptors;

}

std::vector<std::vector<cv::KeyPoint> > Apply_ORB:: getAllImageKeyPoints()
{
	if(all_keypoints.empty())
	{
		//exit with some status
	}
	return all_keypoints;
}


Apply_ORB::~Apply_ORB()
{
    //dtor
}
