#ifndef GMM_H_
#define GMM_H_
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
class GMM
{
public:
	//��˹ģ�͵����������������е�ʵ�֣�Ϊ5
	static const int K = 5;
	//GMM�Ĺ��캯������ model �ж�ȡ�������洢
	GMM(cv::Mat& _model);
	//����ĳ����ɫ����ĳ������Ŀ����ԣ���˹���ʣ�
	double possibility(int, const cv::Vec3d) const;
	//����������Ȩ��
	double tWeight(const cv::Vec3d) const;
	//����һ����ɫӦ���������ĸ��������˹������ߵ��
	int choice(const cv::Vec3d) const;
	//ѧϰ֮ǰ�����ݽ��г�ʼ��
	void learningBegin();
	//��ӵ����ĵ�
	void addSample(int, const cv::Vec3d);
	//������ӵ����ݣ������µĲ������
	void learningEnd();
private:
	//����Э���������������ʽ��ֵ
	void calcuInvAndDet(int);
	//�洢GMMģ��
	cv::Mat model;
	//GMMģ���У�ÿ����˹�ֲ���Ȩ�ء���ֵ��Э����
	double *coefs, *mean, *cov;
	//�洢Э������棬���ڼ���
	double covInv[K][3][3];
	//�洢Э���������ʽֵ
	double covDet[K];
	//����ѧϰ�����б����м����ݵı���
	double sums[K][3];
	double prods[K][3][3];
	int sampleCounts[K];
	int totalSampleCount;
};
#endif
