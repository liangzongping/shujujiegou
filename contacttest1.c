#include"contact1.h"
int main()
{

	int input;
	con* head = NULL;
	//����ͨѶ¼
	conload(&head);
	do
	{
		int n = 0;
		int k;
		menu();
		scanf("%d", &input);
		switch (input)
		{
			//����Ҳ���޸�head,ҲҪ������ָ��
		case 0:
			consave(head); 
			condestroy(&head);
			printf("\n�˳�����\n"); break;
		case 1:
			printf("��������˵���Ϣ(���0��ʾ��������)\n");
			//��Ҫ�޸�head,��head����Ϊָ�룬��Ҫ������ָ��
			createcon(&head);
			break;
		case 2:conprint(head); break;
		case 3:
			printf("������ɾ���ڼ���\n");
			scanf("%d", &k);
			condele(&head, k); break;
		case 4:
			printf("���������ĸ���ź����\n");
			scanf("%d", &k);
			conInsert(&head, k);
			break;
		case 5:
			printf("�������޸ĵڼ���\n");
			scanf("%d", &k);
			conrevise(&head, k);
			break;
		case 6:compute(head);
			break;
		case 7:conclear(&head);
			break;
		}
	} while (input);
}