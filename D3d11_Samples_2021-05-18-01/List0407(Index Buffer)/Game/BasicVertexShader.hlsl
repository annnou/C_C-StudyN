// float4	�f�[�^�^
// pos		�ϐ���
// POSITION	�Z�}���e�B�b�N(�f�[�^�̈Ӗ��A�����A�g��)
float4 main(float4 pos : POSITION) : SV_POSITION
{
	float4 output;
	output = pos;
	//output.x += -0.5;
	return output;
}
// SV_POSITION
//		���_�V�F�[�_�[���v�Z���ʂƂ��ďo�͂���ʒu���W
//		�W�I���g���[�V�F�[�_�[�̓��͂ƂȂ�
