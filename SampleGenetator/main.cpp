//std
#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <cstdint>
#include <functional>
#include <thread>
#include <mutex>
#include <memory>
#include <iomanip>
#include <sstream>
//3rd
#include <leveldb/db.h>
#include <leveldb/write_batch.h>
//own
#include "caffe.pb.h"
#include "SampleGenetator.h"
#include "scopeExit.h"

static const uchar bgColor = 155;
static const uchar fgColor = 0;

static std::wstring getChineseTable()
{
	static const std::wstring chineseTable = L"��һ�ǲ�����������������������ϴ�Ϊ�͹��ص���˵ʱҪ�ͳ����Ҳ������ܶ����ǵ���������֮������������õ�����Ȼ�����³ɷ��ྭôȥ��ѧ�綼ͬ�ֵ�û�����𿴶���ֻ�����С����Щ������������ǰ������ֻ����ʵ�վ������������볤�ѻ�ʮ��ڹ����ѹ�ʹ������֪ȫ���ֹص���ҵ�⽫���߼����ʺ����ز�����Ӧս��ͷ���������������ʲ���Ȳ����¼����������˹�»��ϻ��ش����ű��ϸ���λ�ζ����γ��Ⱥ�ͨ�̶�ԭ������������Ա��ˮ�����۴�������뼸������ƽϵ�����������Ů�������ܺε������ٱ��Žᷴ��Ŀ̫���ٸн������ӱس����ƹ�����ֱ������ɽ��ָ����ͳ�������������վ���չ���˾��������������ȴ�����ǿ��������Ȩ˼��������ʽɫ·����Ʒס������ݳ̱������Ÿý�����ȡ�����������칲ȷ��ʦ�������Ժ��ʶ���������Ц�ɷ粽���ո�������������ÿ�ó��׼��ַ��������ԪӢʿ֤��ʧת����׼��ʼ���ش�δԶ��̨��Ӱ�����ְ����������������������ż�����ۻ�������ʯ������������뼼��Լʾ����Ϣ�����ƹٻ�Ͼ���֧����Խ�������������д����˹����Ƭʷί��������������ũ��װ���԰ɰ����̸��ͼ����������ҽ��ͻר�Ѻž����ܽ�ע�����������ѡ������������Ʋ�ϣ���ڹ��������Ͷĳ����ά�ﻮ���³�����̬�������ɺ�����Ӫ�ǹ�������־��վ�ϰ������幩Ч��ʩ���������մ���ƾ����ĸ��������Ⱥ��ʰ�����Χ��֯����˫���ͼͲɾ�ɱ�������ܵͳ�����ֹϸԸǧֵ����Ǯ�������������������޴���ְ�ٿ��ַ����ë״������������µ�У�ഴ�پô��ӡ�����Թ�����Ԥ˭��������΢����ͼ�Ѫ������ҩ�ʲ�ҹʡ��ϲ��Դʳ�մ���½ϰ�þ��Ͳƻ��Ÿ��ɻ��׾���ģ�为��ͣľ�������ɲ����޳����Է��������켤��������ݼ����е��ݾ��˼������ڻ���ʹ����Э��ռ������Ƥ��ʤ�����������������������ѹ�����������ִ���ҿ���׷�������꺽�Ź�����������˰���ҷݴ��ձ���ݽŸŶ��ٸ��ؾƵ����л��������������汦���;��˵ܵǻ���������ŷ����Σæ�˰���黵����������������¶����ζҰ����ɳ�������������弪������ϲ��������ɢ����������ȹ�ǹȱ¥���к������󻭰�����������ƿ��Ź�ϯ����л³�������Ҿ�����ʫ�ظϾ�Ʊ������ھɶ�̽��¼Ҷ���總���������ѽ��ͥ���龦���˳��ҡ�л��Ѳ�ν�����������������Ī�����ʴ�ʥ��Ѱ��˯��������ŵ�װ���������ը���彡���Թ��Ƚ������԰ı�α�ץ�ٹ�����������������ѩ����ү��ƪ����ݱ鷲������̹ţ��ֽ��ѵ˽ׯ��˿����ɭ��Ĭ��Ϸ����Ƿ����ɸ���������������̰�����Ū�������ڴ�ӵͽķ������Ȥ������ӭ��������������͸������Ŭ�ݻ���;��������Ѹ��ó��Ψ���ֿ⼣�Ⱦ��ִ���������ΰ�鴨�껺Ǳ���۵���������찣����ֲ������ҳ������֣��������쳼����Ⱦʢŭ��Բ�����ղ������ԳϿ����Ͱ�÷����Ħ��ĩ�˱��Ķ���Ӳ�󽯲��趩�ʳ���ħ���غ�Υ���˻�ҷ���������������Ԯ������վ��ƫ���´��ξ��޶�ǽ��Ϯ���������ɲຫðծ���ڹ����ͯ�̳˹ҽ��ܺ�����Ѷ�泹���ɱ�������ϴ�껼�����ǩ�ɱ�֢������������۲˱շ��쳷��輲Ե���ʶ��̼�����β��͵�����פ���˰��ŵ���޷�����̾�����������վ۾�ǡ�����Ҳ�����Ļӳ��̩�������������ݹ����ĳ��������±���������������������Ż��ֺ��ȵ����ױ���������ƶż�������Ȧ���������ͧ�Գ����Ͼ����������������̧���������������ضܱ����﷦¡��ū��ɥ�۶������ƾ�������ּ����÷ƽ��������ҵ�������Ϥ�ٷ���׳����ɨ����ֳ��ì���ʷ���ʣ��������Һ����������������ü�Ǹ���������ͦ�����Ҽ��������豲���컬ȯ���������������ĺ�֦��īв�������������ƭ���ý���������ϧ�ں���Ծʬ����ʻ�������ݲᴢƮɣ�вҽ��ٲ���Ƶ��ĥ��аײ�����Ѳ�ռ����������ƽ�ȼ����α�������Ļ�Ȱ�����ڽ��Ư���ܶ��������ϸ��׼�������������Ũ�����񸹵��ߴ�����ò�����������������δ������ɸֹ��ķ��̵��پ�ѯ�����ʳ��һ��ο�͢�Ķ�Ǩ��ο��������ԹЬ����ȪӿϽ����ϼ�κ��ף���ºݼ�еҧ�ڳ༷������������������è�������ǣ���������ּ���Ա��ߺ�������ɪ����ѷ���۶���˥ƿ���������ǳ���¬�̹���ң�������븧ǳ�ؾ��꾧��Ͽ��������þ���Ϳ������ú�ܹ�ʪѭů�Ǹ�����ñ����̤��Ԭ������β�����������Ŧ�Ʋ����ͭ�ݿ�Ѻ��Įƣ��ǲ����ȭ��б��ϡ�ݷ����߶����ڻ��̺갩��������ҫŤ̳�ֲ��淥���͹�����Ĺ������ƴ��׽��ˢ���ӹ�Ъ�����鴮�޽ɻ�Ӯ���Ұ����ݴ���βտ�ַ�Ӹ����������լ���ں��������������������ҷ�̰���������������ֹ�ö������˧������������޵������˲����Ӵ��Ӷ���ƥ������ǻ����������糦��������ӥ��������ĵ��ټ��Ǻ���Ѩ��׿����Ĥ��Ƿ������ã��Ѧ���ԥθ�����ʰ����Я������������ǿ��ǰ���ഭ�ֲ�¯������̥���߽�ιɵĽ����ȹ���������Ǭ����ͤϦ���������ѷ�й�˰�ɮ����������Ф��ϼ��ԣ��ժ�����������������轮����η���Ҳ���������ߵɵ�©�ְ�����¹����������̲�޴߳��������͹��Ȳ����ä��ɶ�ͳ���ĨͲ��㰦�Ӹ����ĺ������������������˳��óý�ӯ�̳�˲ӤТ�������±γ���ξ������Ѽ�����������ر���ɩ��̷��ӹǸ֥������̯���Խ��¾���������̴�н�ܳܽ����켢�β�������Ƽ��׬���賫��ݺ�������Ԩ��Ϫ������Ԣ��ɡ�˱�Ų��֬�ѿ�����ʨ�����ο�����������Ƣ�۳ռ�����������ž��ɧ����ճ����İխ�����½�ɲ��â��Ƹ������������ˣ�����ÿ��Ķ��Ѻ�ˤ�����������ͻ���׹ɷ�������´����̰�ԡ�Ļ�����ƨ������׫Х��õ˶����ϥҦï����Գկˡ���ݳ�����̺����۳��÷��ξ뺭ȸѮ˺��֫¢����é����Ҥ��ǫ����ѫ�ν�������ש������Ķ������צ���������̿��գ��£�Ⱦ�����ˬ������ڹ����ݹ�����������ϱ��Ϲԩѻ��������մթի�����ɷĹ�Ͱ���̸���г�ݹ�϶�����ٶ�ù�������ɴȹ�����������ʲ�Ʃ���������������������׵���������ܴ���ն���������ƹ�������²����«ƻж��Կ�굻�����������ĸ�׮����Ȣĭɤ���Է����ϳ������������̾ձ��Ƕ���ӱм�Ϻ���ͺ��Ӵ����Ǵ�����ͱлб���о֭��¿�ྸӶµ������������ɺ���а����������鴱�ܻ߶ò��ع��︿�����������俱�����鳴�ӳ�����������ʿ�ҥį˦������ؤӾ���ⶣ�����������������ʴ��ܽ����ɹ˪���̻��������ױ��Ǧ�������������Ȯ��������ּյ�ļ����ª��ֶŰ��Ө�Ʒ��ʿ�ྥ�����޽�����ť�׹���и�����ȸ�����γ���г��˸��Ȱ���׾��̺ͩɰкçƺ��ɼ������Ӭ�굷���۽��ٻ�����ѿ��̼�����������ȿ���̶�������ή����Ͼ���������ĺ�ý븫������˻������ɾӣ�����ҰӲϷ�����ұ�ӱ�§�����������յ��֨�������ʸ������Ю������ѱ����̱������Ƨ��Ƕ������ɬ�ʱĽ�߶���Ϻ��ơ����Ż��͹Ϩ�Ѱ������Ž����鼬���������Ⱦ���Ʋ�ڷ๶��������ƴ�����ݺ���������������������է������Ϲ�����������®����¶�Ϳ���˨���ð����Ѵ������ƽ����л�����հ­�𵿺��������̭���⿻��ſ�����������Ⱥ������̿Ĳ�դ����Ѭĵ׺���淾�鱹ġ������ֿ�����������������ֲ׵�����������Ĵ�洧ո�Ͽ�Ǣ�ٳ�̵֩����з����̲���ϻå��׶���ܿ����㺷�һ޴׾�ز���޻���������±�ѥ�洯����꽴���ܽ�̦����Ͽ������Ⱦ����Ի��������뻾�����ز��Ѷ��ͱ���ƴ������������������ֺ�尰��˩��ų���š��������ε��ջޱ��������ߴ��Ρ�����ް������������������ݷ㿽��έ�����Ȱ��߱躿�ϵ���˲�ذ���ͺ�����������¸�ܻȿ���բ����������������������ѳ�������������������߳��ٹ贶����ʺ������ǯ�й���Ÿ���Ź��ڽ�ͱ���������Ÿ��ŧ�����ϲ�����ɸ�˱Բ��ض���ӫ������ج��������Ǻ��̴���Ծ�ө��������Ⲻƹ��ձ��ɦ�����ᰪ������ӽ������ƴ����쵪���ߴ���Ϭ��������ê��Ҿ��㾻��������������ȵ��Ģ��п��ᣰ����̳�������ߺ�մ�Φ������̻���׸�ٿ������������Ҹ�����Ӹ�魼������˰�Ȭ������������������߽�������ե����ҿ�̣�����޾���˱�������������Ϻ���ͫư�۳Ӷ���±���޵�����Ѵ���󲳹��ڹ�������﷤���Ͳ�����Ͱ��ü�������������������ԯ����ղ���Ш���������Ҵԧ�տ�����ӻ�Ϸ��ĸ�����źЫҬ��Ţ���ȳպ�����������Ӽ����ǭ���ѽ���ʭ¨���׻���ű���������¦�����԰���᫾�Ѣ����ͮ���Ǻ�����򼶻�����Ǽ�����Ÿ�ӧ����ű�ٿ��������ﴻ�궧��Ŵ�����������������������꼸̻��Ҩ���Ҳ��Ʋt���������������������ա������辿��̲����Ⱥ�黷���ɻ������Ҽ������ϳ����ﱱ��Ա�����ȿ��������í�����ް����������ݩ����";
	return chineseTable;
}
static int getRandomValue(const int minValue, const int maxValue)
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
	cv::Mat image;
};
static cv::Mat addSaltNoise(const cv::Mat& grayImg)
{
	cv::Mat resultImg = grayImg.clone();
	cv::Mat saltPepperNoise = cv::Mat::zeros(resultImg.rows, resultImg.cols, CV_8UC1);
	cv::randu(saltPepperNoise, 0, 255);
	const cv::Mat black = saltPepperNoise < 10;
	const cv::Mat white = saltPepperNoise > 245;
	resultImg.setTo(255, white);
	resultImg.setTo(0, black);
	return resultImg;
}
static cv::Mat addGaussianNoise(const cv::Mat& grayImg)
{
	cv::Mat resultImg = grayImg.clone();
	cv::Mat noise = cv::Mat::zeros(resultImg.size(), CV_8UC1);
	cv::randn(noise, 8, 30);
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
	const int shiftDist = getRandomValue(1, 3);
	cv::Mat result = grayImg.clone();
	for (int y = 0; y < result.rows; y++)
	{
		uchar* lineData = result.data + y*result.cols;
		memcpy(lineData, lineData + shiftDist, result.cols - shiftDist);
		memset(lineData + (result.cols - shiftDist), bgColor, shiftDist);
	}
	return result;
}
static cv::Mat horizontalShiftRight(const cv::Mat& grayImg)
{
	const int shiftDist = getRandomValue(1, 3);
	cv::Mat result = grayImg.clone();
	for (int y = 0; y < result.rows; y++)
	{
		uchar* lineData = result.data + y*result.cols;
		memcpy(lineData + shiftDist, lineData, result.cols - shiftDist);
		memset(lineData, bgColor, shiftDist);
	}
	return result;
}
static cv::Mat verticalShiftUp(const cv::Mat& grayImg)
{
	const int shiftDist = getRandomValue(1, 3);
	cv::Mat result = grayImg.clone();
	for (int y = 0; y < result.rows - shiftDist; y++)
	{
		const uchar* srcLineData = result.data + (y + shiftDist)*result.cols;
		uchar* dstLineData = result.data + y*result.cols;
		memcpy(dstLineData, srcLineData, result.cols);
	}
	for (int y = result.rows-shiftDist; y < result.rows; y++)
	{
		uchar* dstLineData = result.data + y*result.cols;
		memset(dstLineData, bgColor, result.cols);
	}
	return result;
}
static cv::Mat verticalShiftDown(const cv::Mat& grayImg)
{
	const int shiftDist = getRandomValue(1, 3);
	cv::Mat result = grayImg.clone();
	for (int y = result.rows - shiftDist; y >= shiftDist; y--)
	{
		const uchar* srcLineData = result.data + (y - shiftDist)*result.cols;
		uchar* dstLineData = result.data + y*result.cols;
		memcpy(dstLineData, srcLineData, result.cols);
	}
	for (int y = 0; y < shiftDist; y++)
	{
		uchar* dstLineData = result.data + y*result.cols;
		memset(dstLineData, bgColor, result.cols);
	}
	return result;
}
static cv::Mat addSkew(const cv::Mat& grayImg)
{
	cv::Mat result = grayImg.clone();
	const int degree = getRandomValue(-20, 20);
	const cv::Point center(result.cols / 2, result.rows / 2);
	const cv::Mat rotMatS = cv::getRotationMatrix2D(center, degree, 1.0);
	warpAffine(result, result, rotMatS, result.size(), 1, 0, bgColor);
	return result;
}
static cv::Mat perTransform(const cv::Mat& grayImg)
{
	cv::Mat result = cv::Mat(grayImg.size(), CV_8UC1);
	result.setTo(bgColor);
	const int imgWidth = result.cols;
	const int imgHeight = result.rows;	
	std::vector<cv::Point2f> corners(4);
	corners[0] = cv::Point2f(0, 0);
	corners[1] = cv::Point2f(imgWidth - 1, 0);
	corners[2] = cv::Point2f(0, imgHeight - 1);
	corners[3] = cv::Point2f(imgWidth - 1, imgHeight - 1);
	//TODO : random it
	std::vector<cv::Point2f> corners_trans(4);
	corners_trans[0] = cv::Point2f(0, 0);
	corners_trans[1] = cv::Point2f(imgWidth-1, 0);
	corners_trans[2] = cv::Point2f(0, imgHeight - 1);
	corners_trans[3] = cv::Point2f(imgWidth-1, imgHeight - 1);
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
		const uchar* p = grayImg.ptr<uchar>(i);
		for (int j = 0; j < imgWidth; j++)
		{
			int y = points_trans[count].y;
			int x = points_trans[count].x;
			if (y >= 0 && y < imgHeight)
			{
				uchar* t = result.ptr<uchar>(y);
				t[x] = p[j];
				count++;
			}
		}
	}
	return result;
}
static std::vector<SampleDesc> genSample(const wchar_t txtChar, const SampleStyle style, const int standardSize,const int singleParm,const int multiParam)
{
	std::vector<SampleDesc> result;
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
		return result;
	}
	else
	{
		cv::resize(smoothedImg, standardImg, cv::Size(standardSize, standardSize), 0.0, 0.0, cv::INTER_AREA);
	}
	//process chain
	//////////////////////////////////////////////////////////////////////////
	using procFuncType = std::function<cv::Mat(const cv::Mat&)>;
	std::vector<procFuncType> procFuncs{
		addSaltNoise,
		addGaussianNoise,
		addGaussianSmooth,
		horizontalShiftLeft,
		horizontalShiftRight,
		verticalShiftUp,
		verticalShiftDown,
		addSkew
		//perTransform
	};
	//////////////////////////////////////////////////////////////////////////
	//standard
	SampleDesc sample;
	sample.txtChar = txtChar;
	sample.image = standardImg;
	result.push_back(sample);
	//////////////////////////////////////////////////////////////////////////
	//single
	const int singleSample = singleParm;
	for (int i = 0; i < singleSample; i++)
	{
		for (auto& func : procFuncs)
		{
			sample.image = func(standardImg);
			result.push_back(sample);
		}
	}
	//////////////////////////////////////////////////////////////////////////
	//random
	const int chainSamples = multiParam;
	for (int i = 0; i < chainSamples;i++)
	{
		const int chainLen = 2;
		auto img = standardImg.clone();
		for (int j = 0; j < chainLen; j++)
		{
			const int curIdx = getRandomValue(0, procFuncs.size()-1);
			auto& func = procFuncs[curIdx];
			img = func(img);
		}
		sample.image = img;
		result.push_back(sample);
	}
	return result;
}
//copied from caffe [https://github.com/BVLC/caffe/blob/c7ee2615a8df2dedb408ff9c2c842e5f4f42a310/include/caffe/util/format.hpp]
static inline std::string format_int(int n, int numberOfLeadingZeros = 0) {
	std::ostringstream s;
	s << std::setw(numberOfLeadingZeros) << std::setfill('0') << n;
	return s.str();
}
static void genSamples(const std::wstring& charList, const std::string& trainFilePath, const std::string& validateFilePath,const std::string& reportFilePath)
{
	const int standardSize = 32;
	const auto styles = std::vector<SampleStyle>{
		SampleStyle("΢��������.ttf"),
		SampleStyle("���������μ���.ttf")
	};

	std::ofstream ofsReport(reportFilePath);

	// leveldb
	leveldb::Options options;
	options.error_if_exists = true;
	options.create_if_missing = true;
	options.write_buffer_size = 268435456;
	leveldb::Status status;
	//train
	leveldb::DB* trainDb = nullptr;
	status = leveldb::DB::Open(
		options, trainFilePath, &trainDb);
	if (!status.ok())
	{
		std::cerr << "failed to open levelDB , path = " << trainFilePath << std::endl;
		return;
	}
	SCOPEEXIT(delete trainDb;);
	leveldb::WriteBatch* trainBatch = new leveldb::WriteBatch();
	SCOPEEXIT(delete trainBatch;);
	//validate
	leveldb::DB* validateDb = nullptr;
	status = leveldb::DB::Open(
		options, validateFilePath, &validateDb);
	if (!status.ok())
	{
		std::cerr << "failed to open levelDB , path = " << validateFilePath << std::endl;
		return;
	}
	SCOPEEXIT(delete validateDb;);
	leveldb::WriteBatch* validateBatch = new leveldb::WriteBatch();
	SCOPEEXIT(delete validateBatch;);
	//
	const int batchSize = 3000;
	int trainSampleIdx = 0;
	int validateSampleIdx = 0;
	SCOPEEXIT(if(trainSampleIdx % batchSize != 0){trainDb->Write(leveldb::WriteOptions(), trainBatch);});
	SCOPEEXIT(if (validateSampleIdx % batchSize != 0){ validateDb->Write(leveldb::WriteOptions(), validateBatch); });

	//////////////////////////////////////////////////////////////////////////
	std::cout << "---------------------------" << std::endl;
	std::cout << "generating samples ..." << std::endl;
	std::vector<SampleDesc> train_samples;
	std::vector<SampleDesc> validate_samples;
	std::map<wchar_t, int> train_statistics;
	std::map<wchar_t, int> validate_statistics;
	const int train_single_param = 20;
	const int train_multi_param = 40;
	const int validate_single_param = 6;
	const int validate_multi_param = 15;
	//gen samples
	if (charList.size() < 10)
	{
		for (const auto& txtChar : charList)
		{
			//asyn
			for (const auto& style : styles)
			{
				//train
				const auto trainSampleSet = genSample(txtChar, style, standardSize, train_single_param, train_multi_param);
				std::copy(trainSampleSet.cbegin(), trainSampleSet.cend(), std::back_inserter(train_samples));				
				//validate
				const auto validateSampleSet = genSample(txtChar, style, standardSize, validate_single_param, validate_multi_param);
				std::copy(validateSampleSet.cbegin(), validateSampleSet.cend(), std::back_inserter(validate_samples));
				train_statistics[txtChar] += trainSampleSet.size();
				validate_statistics[txtChar] += validateSampleSet.size();
			}
		}	
	}
	else
	{
		int idx = 0;
		auto synFetchCharFunc = [&idx,&charList](wchar_t& txtChar)->bool{
			if (idx >= charList.size())
			{
				return false;
			}
			txtChar = charList[idx];
			idx++;
			return true;
		};
		std::vector<std::thread> threads(4);
		std::mutex mtx;
		for (size_t i = 0; i < threads.size(); i++)
		{
			threads[i] = std::thread([&styles, &synFetchCharFunc, &standardSize, &mtx, &train_samples, &validate_samples, &train_statistics, &validate_statistics,
				&train_single_param, &train_multi_param, &validate_single_param, &validate_multi_param]{
				while (true)
				{
					wchar_t txtChar = 0;
					//syn block
					{
						std::lock_guard<std::mutex> locker(mtx);
						const bool isOK = synFetchCharFunc(txtChar);
						if (!isOK)
						{
							break;
						}
					}					
					std::vector<SampleDesc> trainSampleSet;
					std::vector<SampleDesc> validateSampleSet;
					//asyn block
					{
						for (const auto& style : styles)
						{
							//train
							trainSampleSet = genSample(txtChar, style, standardSize, train_single_param, train_multi_param);
							//validate
							validateSampleSet = genSample(txtChar, style, standardSize, validate_single_param, validate_multi_param);
						}						
					}
					//syn block
					{
						std::lock_guard<std::mutex> locker(mtx);
						std::copy(trainSampleSet.cbegin(), trainSampleSet.cend(), std::back_inserter(train_samples));
						std::copy(validateSampleSet.cbegin(), validateSampleSet.cend(), std::back_inserter(validate_samples));
						train_statistics[txtChar] += trainSampleSet.size();
						validate_statistics[txtChar] += validateSampleSet.size();
					}
				}			
			});
		}
		for (size_t i = 0; i < threads.size(); i++)
		{
			threads[i].join();
		}
	}
	std::cout << "generate samples done." << std::endl;
	std::cout << "train sample set : " << train_samples.size() << std::endl;
	std::cout << "validate sample set : " << validate_samples.size() << std::endl;
	ofsReport << "train sample set : " << train_samples.size() << std::endl;
	ofsReport << "validate sample set : " << validate_samples.size() << std::endl;
	ofsReport << "---------------------------" << std::endl;
	ofsReport << "train total char count : " << train_statistics.size() << std::endl;
	ofsReport << "train details : " << std::endl;
	for (const auto item : train_statistics)
	{
		ofsReport << item.first << "\t" << item.second << std::endl;
	}
	ofsReport << "---------------------------" << std::endl;
	ofsReport << "validate total char count : " << validate_statistics.size() << std::endl;
	ofsReport << "validate details : " << std::endl;
	for (const auto item : validate_statistics)
	{
		ofsReport << item.first << "\t" << item.second << std::endl;
	}
	std::cout << "---------------------------" << std::endl;
	std::cout << "shuffling samples ..." << std::endl;
	//shuffle
	const auto randSeed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(train_samples.begin(), train_samples.end(), std::default_random_engine(randSeed));
	std::shuffle(validate_samples.begin(), validate_samples.end(), std::default_random_engine(randSeed));
	std::cout << "shuffle samples done." << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << "writing samples ..." << std::endl;
	//dump
	//commmon
	//dump func
	auto dumpData = [&standardSize, &batchSize](const SampleDesc& sample, leveldb::DB*& db, leveldb::WriteBatch*& batch, const int total, int& curSampleIdx){
		//details
		const auto& img(sample.image);
		std::string key_str = format_int(curSampleIdx, 8);
		std::string value;
		caffe::Datum datum;
		datum.set_channels(1);
		datum.set_height(standardSize);
		datum.set_width(standardSize);
		datum.set_label(sample.txtChar);
		datum.set_data(img.data, img.rows*img.cols);
		datum.SerializeToString(&value);
		batch->Put(key_str, value);
		//batch write
		curSampleIdx++;
		if (curSampleIdx % batchSize == 0)
		{
			db->Write(leveldb::WriteOptions(), batch);
			delete batch;
			batch = new leveldb::WriteBatch();
			std::cout << "current text : " << sample.txtChar << std::endl;
			std::cout << "progress : " << curSampleIdx << "/" << total << std::endl;			
		}		
	};
	//train set
	for (const auto& sample : train_samples)
	{
		dumpData(sample, trainDb, trainBatch, train_samples.size(), trainSampleIdx);
	}
	//validate set
	for (const auto& sample : validate_samples)
	{
		dumpData(sample, validateDb, validateBatch, validate_samples.size(), validateSampleIdx);
	}
	std::cout << "write done!" << std::endl;
	std::cout << "---------------------------\n\n"<< std::endl;
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
		const auto txtChar = chineseTable[getRandomValue(0, chineseTable.size()-1)];
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
	//
	system("del /q train.data");
	system("del /q test.data");
	genSamples(getChineseTable(), "train.data","test.data","report.txt");
	//parserSampleData("΢��������.data");
	return 0;
}