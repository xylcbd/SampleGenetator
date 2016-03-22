#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <cstdint>
#include "SampleGenetator.h"

static const uchar bgColor = 155;
static const uchar fgColor = 0;

static std::wstring getChineseTable()
{
	static const std::wstring chineseTable = L"��һ�ǲ�����������������������ϴ�Ϊ�͹��ص���˵ʱҪ�ͳ����Ҳ������ܶ����ǵ���������֮������������õ�����Ȼ�����³ɷ��ྭôȥ��ѧ�綼ͬ�ֵ�û�����𿴶���ֻ�����С����Щ������������ǰ������ֻ����ʵ�վ������������볤�ѻ�ʮ��ڹ����ѹ�ʹ������֪ȫ���ֹص���ҵ�⽫���߼����ʺ����ز�����Ӧս��ͷ���������������ʲ���Ȳ����¼����������˹�»��ϻ��ش����ű��ϸ���λ�ζ����γ��Ⱥ�ͨ�̶�ԭ������������Ա��ˮ�����۴�������뼸������ƽϵ�����������Ů�������ܺε������ٱ��Žᷴ��Ŀ̫���ٸн������ӱس����ƹ�����ֱ������ɽ��ָ����ͳ�������������վ���չ���˾��������������ȴ�����ǿ��������Ȩ˼��������ʽɫ·����Ʒס������ݳ̱������Ÿý�����ȡ�����������칲ȷ��ʦ�������Ժ��ʶ���������Ц�ɷ粽���ո�������������ÿ�ó��׼��ַ��������ԪӢʿ֤��ʧת����׼��ʼ���ش�δԶ��̨��Ӱ�����ְ����������������������ż�����ۻ�������ʯ������������뼼��Լʾ����Ϣ�����ƹٻ�Ͼ���֧����Խ�������������д����˹����Ƭʷί��������������ũ��װ���԰ɰ����̸��ͼ����������ҽ��ͻר�Ѻž����ܽ�ע�����������ѡ������������Ʋ�ϣ���ڹ��������Ͷĳ����ά�ﻮ���³�����̬�������ɺ�����Ӫ�ǹ�������־��վ�ϰ������幩Ч��ʩ���������մ���ƾ����ĸ��������Ⱥ��ʰ�����Χ��֯����˫���ͼͲɾ�ɱ�������ܵͳ�����ֹϸԸǧֵ����Ǯ�������������������޴���ְ�ٿ��ַ����ë״������������µ�У�ഴ�پô��ӡ�����Թ�����Ԥ˭��������΢����ͼ�Ѫ������ҩ�ʲ�ҹʡ��ϲ��Դʳ�մ���½ϰ�þ��Ͳƻ��Ÿ��ɻ��׾���ģ�为��ͣľ�������ɲ����޳����Է��������켤��������ݼ����е��ݾ��˼������ڻ���ʹ����Э��ռ������Ƥ��ʤ�����������������������ѹ�����������ִ���ҿ���׷�������꺽�Ź�����������˰���ҷݴ��ձ���ݽŸŶ��ٸ��ؾƵ����л��������������汦���;��˵ܵǻ���������ŷ����Σæ�˰���黵����������������¶����ζҰ����ɳ�������������弪������ϲ��������ɢ����������ȹ�ǹȱ¥���к������󻭰�����������ƿ��Ź�ϯ����л³�������Ҿ�����ʫ�ظϾ�Ʊ������ھɶ�̽��¼Ҷ���總���������ѽ��ͥ���龦���˳��ҡ�л��Ѳ�ν�����������������Ī�����ʴ�ʥ��Ѱ��˯��������ŵ�װ���������ը���彡���Թ��Ƚ������԰ı�α�ץ�ٹ�����������������ѩ����ү��ƪ����ݱ鷲������̹ţ��ֽ��ѵ˽ׯ��˿����ɭ��Ĭ��Ϸ����Ƿ����ɸ���������������̰�����Ū�������ڴ�ӵͽķ������Ȥ������ӭ��������������͸������Ŭ�ݻ���;��������Ѹ��ó��Ψ���ֿ⼣�Ⱦ��ִ���������ΰ�鴨�껺Ǳ���۵���������찣����ֲ������ҳ������֣��������쳼����Ⱦʢŭ��Բ�����ղ������ԳϿ����Ͱ�÷����Ħ��ĩ�˱��Ķ���Ӳ�󽯲��趩�ʳ���ħ���غ�Υ���˻�ҷ���������������Ԯ������վ��ƫ���´��ξ��޶�ǽ��Ϯ���������ɲຫðծ���ڹ����ͯ�̳˹ҽ��ܺ�����Ѷ�泹���ɱ�������ϴ�껼�����ǩ�ɱ�֢������������۲˱շ��쳷��輲Ե���ʶ��̼�����β��͵�����פ���˰��ŵ���޷�����̾�����������վ۾�ǡ�����Ҳ�����Ļӳ��̩�������������ݹ����ĳ��������±���������������������Ż��ֺ��ȵ����ױ���������ƶż�������Ȧ���������ͧ�Գ����Ͼ����������������̧���������������ضܱ����﷦¡��ū��ɥ�۶������ƾ�������ּ����÷ƽ��������ҵ�������Ϥ�ٷ���׳����ɨ����ֳ��ì���ʷ���ʣ��������Һ����������������ü�Ǹ���������ͦ�����Ҽ��������豲���컬ȯ���������������ĺ�֦��īв�������������ƭ���ý���������ϧ�ں���Ծʬ����ʻ�������ݲᴢƮɣ�вҽ��ٲ���Ƶ��ĥ��аײ�����Ѳ�ռ����������ƽ�ȼ����α�������Ļ�Ȱ�����ڽ��Ư���ܶ��������ϸ��׼�������������Ũ�����񸹵��ߴ�����ò�����������������δ������ɸֹ��ķ��̵��پ�ѯ�����ʳ��һ��ο�͢�Ķ�Ǩ��ο��������ԹЬ����ȪӿϽ����ϼ�κ��ף���ºݼ�еҧ�ڳ༷������������������è�������ǣ���������ּ���Ա��ߺ�������ɪ����ѷ���۶���˥ƿ���������ǳ���¬�̹���ң�������븧ǳ�ؾ��꾧��Ͽ��������þ���Ϳ������ú�ܹ�ʪѭů�Ǹ�����ñ����̤��Ԭ������β�����������Ŧ�Ʋ����ͭ�ݿ�Ѻ��Įƣ��ǲ����ȭ��б��ϡ�ݷ����߶����ڻ��̺갩��������ҫŤ̳�ֲ��淥���͹�����Ĺ������ƴ��׽��ˢ���ӹ�Ъ�����鴮�޽ɻ�Ӯ���Ұ����ݴ���βտ�ַ�Ӹ����������լ���ں��������������������ҷ�̰���������������ֹ�ö������˧������������޵������˲����Ӵ��Ӷ���ƥ������ǻ����������糦��������ӥ��������ĵ��ټ��Ǻ���Ѩ��׿����Ĥ��Ƿ������ã��Ѧ���ԥθ�����ʰ����Я������������ǿ��ǰ���ഭ�ֲ�¯������̥���߽�ιɵĽ����ȹ���������Ǭ����ͤϦ���������ѷ�й�˰�ɮ����������Ф��ϼ��ԣ��ժ�����������������轮����η���Ҳ���������ߵɵ�©�ְ�����¹����������̲�޴߳��������͹��Ȳ����ä��ɶ�ͳ���ĨͲ��㰦�Ӹ����ĺ������������������˳��óý�ӯ�̳�˲ӤТ�������±γ���ξ������Ѽ�����������ر���ɩ��̷��ӹǸ֥������̯���Խ��¾���������̴�н�ܳܽ����켢�β�������Ƽ��׬���賫��ݺ�������Ԩ��Ϫ������Ԣ��ɡ�˱�Ų��֬�ѿ�����ʨ�����ο�����������Ƣ�۳ռ�����������ž��ɧ����ճ����İխ�����½�ɲ��â��Ƹ������������ˣ�����ÿ��Ķ��Ѻ�ˤ�����������ͻ���׹ɷ�������´����̰�ԡ�Ļ�����ƨ������׫Х��õ˶����ϥҦï����Գկˡ���ݳ�����̺����۳��÷��ξ뺭ȸѮ˺��֫¢����é����Ҥ��ǫ����ѫ�ν�������ש������Ķ������צ���������̿��գ��£�Ⱦ�����ˬ������ڹ����ݹ�����������ϱ��Ϲԩѻ��������մթի�����ɷĹ�Ͱ���̸���г�ݹ�϶�����ٶ�ù�������ɴȹ�����������ʲ�Ʃ���������������������׵���������ܴ���ն���������ƹ�������²����«ƻж��Կ�굻�����������ĸ�׮����Ȣĭɤ���Է����ϳ������������̾ձ��Ƕ���ӱм�Ϻ���ͺ��Ӵ����Ǵ�����ͱлб���о֭��¿�ྸӶµ������������ɺ���а����������鴱�ܻ߶ò��ع��︿�����������俱�����鳴�ӳ�����������ʿ�ҥį˦������ؤӾ���ⶣ�����������������ʴ��ܽ����ɹ˪���̻��������ױ��Ǧ�������������Ȯ��������ּյ�ļ����ª��ֶŰ��Ө�Ʒ��ʿ�ྥ�����޽�����ť�׹���и�����ȸ�����γ���г��˸��Ȱ���׾��̺ͩɰкçƺ��ɼ������Ӭ�굷���۽��ٻ�����ѿ��̼�����������ȿ���̶�������ή����Ͼ���������ĺ�ý븫������˻������ɾӣ�����ҰӲϷ�����ұ�ӱ�§�����������յ��֨�������ʸ������Ю������ѱ����̱������Ƨ��Ƕ������ɬ�ʱĽ�߶���Ϻ��ơ����Ż��͹Ϩ�Ѱ������Ž����鼬���������Ⱦ���Ʋ�ڷ๶��������ƴ�����ݺ���������������������է������Ϲ�����������®����¶�Ϳ���˨���ð����Ѵ������ƽ����л�����հ­�𵿺��������̭���⿻��ſ�����������Ⱥ������̿Ĳ�դ����Ѭĵ׺���淾�鱹ġ������ֿ�����������������ֲ׵�����������Ĵ�洧ո�Ͽ�Ǣ�ٳ�̵֩����з����̲���ϻå��׶���ܿ����㺷�һ޴׾�ز���޻���������±�ѥ�洯����꽴���ܽ�̦����Ͽ������Ⱦ����Ի��������뻾�����ز��Ѷ��ͱ���ƴ������������������ֺ�尰��˩��ų���š��������ε��ջޱ��������ߴ��Ρ�����ް������������������ݷ㿽��έ�����Ȱ��߱躿�ϵ���˲�ذ���ͺ�����������¸�ܻȿ���բ����������������������ѳ�������������������߳��ٹ贶����ʺ������ǯ�й���Ÿ���Ź��ڽ�ͱ���������Ÿ��ŧ�����ϲ�����ɸ�˱Բ��ض���ӫ������ج��������Ǻ��̴���Ծ�ө��������Ⲻƹ��ձ��ɦ�����ᰪ������ӽ������ƴ����쵪���ߴ���Ϭ��������ê��Ҿ��㾻��������������ȵ��Ģ��п��ᣰ����̳�������ߺ�մ�Φ������̻���׸�ٿ������������Ҹ�����Ӹ�魼������˰�Ȭ������������������߽�������ե����ҿ�̣�����޾���˱�������������Ϻ���ͫư�۳Ӷ���±���޵�����Ѵ���󲳹��ڹ�������﷤���Ͳ�����Ͱ��ü�������������������ԯ����ղ���Ш���������Ҵԧ�տ�����ӻ�Ϸ��ĸ�����źЫҬ��Ţ���ȳպ�����������Ӽ����ǭ���ѽ���ʭ¨���׻���ű���������¦�����԰���᫾�Ѣ����ͮ���Ǻ�����򼶻�����Ǽ�����Ÿ�ӧ����ű�ٿ��������ﴻ�궧��Ŵ�����������������������꼸̻��Ҩ���Ҳ��Ʋt���������������������ա������辿��̲����Ⱥ�黷���ɻ������Ҽ������ϳ����ﱱ��Ա�����ȿ��������í�����ް����������ݩ����";
	return chineseTable;
}
static unsigned short getRandomValue(const unsigned short minValue, const unsigned short maxValue)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(minValue,maxValue);
	return dis(gen);
}
struct SampleStyle
{
	std::string font;
	SampleStyle(const std::string& _font) :font(_font){}
};
struct SampleDesc
{
	wchar_t txtChar;
	cv::Mat img;
};
static cv::Mat addSaltNoise(const cv::Mat& grayImg)
{
	cv::Mat resultImg = grayImg.clone();
// 	const int noiseCount = getRandomValue(10, resultImg.cols*resultImg.rows / 10);
// 	for (int i = 0; i < noiseCount; i++)
// 	{
// 		const int x = getRandomValue(0, resultImg.cols) % resultImg.cols;
// 		const int y = getRandomValue(0, resultImg.rows) % resultImg.rows;
// 		const auto color = getRandomValue(0, 2);
// 		if (color == 1)
// 		{
// 			resultImg.at<uchar>(y, x) = 255;
// 		}
// 		else
// 		{
// 			resultImg.at<uchar>(y, x) = 0;
// 		}
// 	}
	cv::Mat saltPepperNoise = cv::Mat::zeros(resultImg.rows, resultImg.cols, CV_8UC1);
	cv::randu(saltPepperNoise, 0, 255);
	const cv::Mat black = saltPepperNoise < 30;
	const cv::Mat white = saltPepperNoise > 225;
	resultImg.setTo(255, white);
	resultImg.setTo(0, black);
	return resultImg;
}
static cv::Mat addGaussianNoise(const cv::Mat& grayImg)
{
	cv::Mat resultImg = grayImg.clone();
	cv::Mat noise = cv::Mat::zeros(resultImg.size(), CV_8UC1);
	cv::randn(noise, 128, 30);
	cv::add(resultImg, noise, resultImg);
	return resultImg;
}
static cv::Mat addGaussianSmooth(const cv::Mat& grayImg)
{
	cv::Mat resultImg = grayImg.clone();
	cv::GaussianBlur(resultImg, resultImg, cv::Size(3, 3), 0.1f);
	return resultImg;
}
static cv::Mat horizontalShiftLeft(const cv::Mat& grayImg)
{
	const int shiftDist = getRandomValue(0, 10);
	cv::Mat result = grayImg.clone();
	for (int y = 0; y < grayImg.rows;y++)
	{
		uchar* lineData = grayImg.data + y*grayImg.cols;
		memcpy(lineData, lineData + shiftDist, grayImg.cols - shiftDist);
		memset(lineData + (grayImg.cols - shiftDist), bgColor, shiftDist);
	}
	return result;
}
static cv::Mat horizontalShiftRight(const cv::Mat& grayImg)
{
	const int shiftDist = getRandomValue(0, 10);
	cv::Mat result = grayImg.clone();
	for (int y = 0; y < grayImg.rows; y++)
	{
		uchar* lineData = grayImg.data + y*grayImg.cols;
		memcpy(lineData + shiftDist, lineData, grayImg.cols - shiftDist);
		memset(lineData, bgColor, shiftDist);
	}
	return result;
}
static cv::Mat verticalShiftUp(const cv::Mat& grayImg)
{
	const int shiftDist = getRandomValue(0, 10);
	cv::Mat result = grayImg.clone();
	for (int y = 0; y < grayImg.rows - shiftDist; y++)
	{
		const uchar* srcLineData = grayImg.data + (y + shiftDist)*grayImg.cols;
		uchar* dstLineData = grayImg.data + y*grayImg.cols;
		memcpy(dstLineData, srcLineData, grayImg.cols);
	}
	for (int y = grayImg.rows-shiftDist; y < grayImg.rows; y++)
	{
		uchar* dstLineData = grayImg.data + y*grayImg.cols;
		memset(dstLineData, 0, grayImg.cols);
	}
	return result;
}
static cv::Mat verticalShiftDown(const cv::Mat& grayImg)
{
	const int shiftDist = getRandomValue(0, 10);
	cv::Mat result = grayImg.clone();
	for (int y = shiftDist; y < grayImg.rows; y++)
	{
		const uchar* srcLineData = grayImg.data + (y - shiftDist)*grayImg.cols;
		uchar* dstLineData = grayImg.data + y*grayImg.cols;
		memcpy(dstLineData, srcLineData, grayImg.cols);
	}
	for (int y = 0; y < shiftDist; y++)
	{
		uchar* dstLineData = grayImg.data + y*grayImg.cols;
		memset(dstLineData, 0, grayImg.cols);
	}
	return result;
}
//-20 -10 10 20
static cv::Mat addSkew(const cv::Mat& grayImg, const int degree)
{
	cv::Mat result = grayImg.clone();
	const cv::Point center(result.cols / 2, result.rows / 2);
	const cv::Mat rotMatS = cv::getRotationMatrix2D(center, degree, 1.0);
	warpAffine(result, result, rotMatS, result.size(), 1, 0, bgColor);
	return result;
}
static cv::Mat perTransform(const cv::Mat& grayImg)
{
	cv::Mat result = grayImg.clone();
	const int imgWidth = result.cols;
	const int imgHeight = result.rows;	
	std::vector<cv::Point2f> corners(4);
	corners[0] = cv::Point2f(0, 0);
	corners[1] = cv::Point2f(imgWidth - 1, 0);
	corners[2] = cv::Point2f(0, imgHeight - 1);
	corners[3] = cv::Point2f(imgWidth - 1, imgHeight - 1);
	//TODO : random it
	std::vector<cv::Point2f> corners_trans(4);
	corners_trans[0] = cv::Point2f(15, 25);
	corners_trans[1] = cv::Point2f(7, 0);
	corners_trans[2] = cv::Point2f(0, imgHeight - 1);
	corners_trans[3] = cv::Point2f(6, imgHeight - 1);
	//action
	cv::Mat transform = cv::getPerspectiveTransform(corners, corners_trans);
	std::vector<cv::Point2f> ponits, points_trans;
	for (int i = 0; i < imgHeight; i++)
	{
		for (int j = 0; j < imgWidth; j++)
		{
			ponits.push_back(cv::Point2f(j, i));
		}
	}
	cv::perspectiveTransform(ponits, points_trans, transform);
	int count = 0;
	for (int i = 0; i < imgHeight; i++)
	{
		uchar* p = result.ptr<uchar>(i);
		for (int j = 0; j < imgWidth; j++)
		{
			int y = points_trans[count].y;
			int x = points_trans[count].x;
			uchar* t = result.ptr<uchar>(y);
			t[x * 3] = p[j * 3];
			count++;
		}
	}
	return result;
}
static cv::Mat genSample(const wchar_t txtChar, const SampleStyle style, const int standardSize)
{
	const int srcSize = 86;
	SampleGenetator paiter(style.font, srcSize);
	//src
	const auto srcImg = paiter.genSample(txtChar, bgColor, fgColor);
	//smooth
	cv::Mat smoothedImg;
	cv::GaussianBlur(srcImg, smoothedImg, cv::Size(3, 3), 1.0f);
	//resize
	cv::Mat standardImg;
	if (!smoothedImg.data)
	{
		std::cout << "style : {" << style.font << "}" << std::endl;
		std::cout << "lost char : txtChar = " << txtChar << ",width=" << smoothedImg.cols << ",height=" << smoothedImg.rows << std::endl;
		standardImg = smoothedImg.clone();
	}
	else
	{
		cv::resize(smoothedImg, standardImg, cv::Size(standardSize, standardSize), 0.0, 0.0, cv::INTER_AREA);
	}
	return standardImg;
}
static void genSamples(const std::wstring& charList, const std::string& sampleFilePath,const SampleStyle style)
{
	//gen samples
	const int standardSize = 32;
	std::vector<SampleDesc> samples;
	for (const auto& txtChar : charList)
	{
		SampleDesc sample;
		sample.txtChar = txtChar;
		sample.img = genSample(txtChar, style, standardSize);
		samples.push_back(sample);
	}

	//dump samples
	std::ofstream ofs(sampleFilePath,std::ios_base::binary);
	int sampleCount = samples.size();
	ofs.write((char*)(&sampleCount), sizeof(sampleCount));
	ofs.write((char*)(&standardSize), sizeof(standardSize));
	for (const auto& sample : samples)
	{
		//txt char
		ofs.write((char*)(&sample.txtChar), sizeof(sample.txtChar));
		//width,height
		const int width = sample.img.cols;
		const int height = sample.img.rows;
		ofs.write((char*)(&width), sizeof(width));
		ofs.write((char*)(&height), sizeof(height));
		for (int y = 0; y < sample.img.rows;y++)
		{
			ofs.write((char*)(sample.img.data + y*sample.img.cols),sample.img.cols);
		}	
	}
}
static std::vector<SampleDesc> parserSampleData(const std::string& sampleFilePath)
{
	std::vector<SampleDesc> samples;
	//load samples
	std::ifstream ifs(sampleFilePath, std::ios_base::binary);
	int sampleCount = 0;
	ifs.read((char*)(&sampleCount), sizeof(sampleCount));
	int standardSize = 0;
	ifs.read((char*)(&standardSize), sizeof(standardSize));
	for (int i = 0; i < sampleCount;i++)
	{
		wchar_t txtChar = L'';
		ifs.read((char*)(&txtChar), sizeof(txtChar));
		int width = 0, height = 0;
		ifs.read((char*)(&width), sizeof(width));
		ifs.read((char*)(&height), sizeof(height));
		cv::Mat srcImg(height, width, CV_8UC1);
		for (int y = 0; y < height; y++)
		{
			ifs.read((char*)(srcImg.data + y*srcImg.cols), srcImg.cols);
		}
		SampleDesc sample;
		sample.txtChar = txtChar;
		sample.img = srcImg;
		samples.push_back(sample);
		cv::imshow("srcImg", srcImg);
		const auto key = cv::waitKey(0);
		if (key == 27)
		{
			break;
		}
	}
	return samples;
}
static void example()
{
	const int srcSize = 86;
	const int standardSize = 32;
	const auto font = R"(���������μ���.ttf)";
	SampleGenetator paiter(font, srcSize);
	const auto chineseTable = getChineseTable();
	while (true)
	{
		const auto txtChar = chineseTable[getRandomValue(0, chineseTable.size())];
		const auto srcImg = paiter.genSample(txtChar, bgColor,fgColor);
		cv::Mat smoothedImg;
		cv::GaussianBlur(srcImg, smoothedImg, cv::Size(3, 3), 1.0f);
		cv::Mat standardImg;
		cv::resize(smoothedImg, standardImg, cv::Size(standardSize, standardSize), 0.0, 0.0, cv::INTER_AREA);
		cv::destroyAllWindows();
		cv::imshow("srcImg", srcImg);
		cv::imshow("smoothedImg", smoothedImg);
		cv::imshow("standardImg", standardImg);
		const auto key = cv::waitKey(0);
		if (key == 27)
		{
			break;
		}
	}
}
int main()
{
	//example();
	const auto styles = std::vector<SampleStyle>{
		SampleStyle("΢��������.ttf"),
		SampleStyle("���������μ���.ttf")
	};
	for (const auto& style : styles)
	{
		const auto sampleFilePath = "samples.data";
		genSamples(getChineseTable(), sampleFilePath,style);
		parserSampleData(sampleFilePath);
	}
	return 0;
}