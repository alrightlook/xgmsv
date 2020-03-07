#pragma once

namespace server
{
	namespace crossgate
	{
		struct xg_packet : public core::packet
		{
			xg_packet(core::packet&& packet) :
				core::packet(packet)
			{}

		};

#define send_raw(str) enqueue_response((uint8*)str, sizeof(str) - 1)

		void handle_echo(xg_packet* packet)
		{
			auto connection = packet->connection;

			if (!connection->send_raw("Echo nr "))
			{
				printf("handle_echo failed.\n");
			}

			printf("handle_echo!\n");
		}

		void handle_fc(xg_packet* packet)
		{
			printf("handle_fc!\n");
		}

		void handle_client_login(xg_packet* packet)
		{
			enum status_code
			{
				success = 0,
				wrong_login_or_banned = 1,
				refuse = 2
			};

			auto connection = packet->connection;

			if (!connection->send_raw("ClientLogin 0 block "))
			{
				printf("handle_client_login failed.\n");
			}

			printf("handle_client_login!\n");
		}

		void handle_char_list(xg_packet* packet)
		{
			enum fields
			{
				name = 0,
				something = 1,
				portrait = 2,
				level = 3,
				vitality = 4,
				strength = 5,
				toughness = 6,
				quickness = 7,
				magic = 8,
				fire = 9,
				wind = 10,
				earth = 11,
				water = 12,
			};

			auto connection = packet->connection;

			if (!connection->send_raw(R"(CharList 0 jason|0\\z241400\\z2\\z15\\z0\\z0\\z0\\z15\\z0\\z0\\z100\\z0\\z2\\zjason\\z2\\z����\\z2\\z106002\\z-1| )"))
			{
				printf("handle_char_list failed.\n");
			}

			printf("handle_char_list!\n");
		}

		void handle_char_login(xg_packet* packet)
		{
			auto connection = packet->connection;
			connection->send_raw(R"(LI 3I3 1JayvY 1 0 )");
			connection->send_raw(R"(CC 0 hV p J c 6 0 0 0 0 -1 )");
			connection->send_raw(R"(MN ����ҽԺ\\z0 )");
			connection->send_raw(R"(CP 1|155|155|185|185|15|0|0|0|15|50|50|50|0|16|1|23|23|23|107|107|60|100|100|0|0|0|5000|0|jason|| )");
			connection->send_raw(R"(CP2 1|0|0|0|0|0|0|0|0|0|0|100|0|0|0|0|241400|10|100| )");
			connection->send_raw(R"(CJ 1 ��ϰ����ʿ )");
			connection->send_raw(R"(CS 0|||||||||||1|||||||||||2|||||||||||3|||||||||||4|||||||||||5|||||||||||6|||||||||||7|||||||||||8|||||||||||9|||||||||||10|||||||||||11|||||||||||12|||||||||||13|||||||||||14||||||||||| )");
			connection->send_raw(R"(TITLE ��η�ļž�|0|17|��ϰ����ʿ|1|161||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||)");
			connection->send_raw(R"(I )");
			connection->send_raw(R"(EP 0 0 )");
			connection->send_raw(R"(KP 0 1|101321|4|93|93|99|99|1|16|1|48|40|34|101|100|24|0|40|60|0|10|1|���ֺ����||0|0| )");
			connection->send_raw(R"(KP2 0 1|2|9|4|5|3|25|0|45|-10|0|0|0|0|0|0|1| )");
			connection->send_raw(R"(PT 0 0|7300|����|������ͨ������������|0|1|1141|0|1|7400|����|�ܷ��������������Ĵ��|0|1|72|1|2|407|������\SLV8|�������ǰ����λ��һ���������˺������ȼ��ı乥������|40|1|117|2|3|1238|����ֹˮ-��|���о���ظ�һ���������������� �ܺ��������ֵԽ�߻ظ���������Խ��(ע��ͻظ����޹�)��ʹ�ú��޷�������������\S|135|1|72|3|)");
			connection->send_raw(R"(FS 0 )");
			connection->send_raw(R"(MC 0 hV 0 0 p k bFX agh 0 )");
			connection->send_raw(R"(AB |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||)");
			connection->send_raw(R"(ABG |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||)");
			connection->send_raw(R"(C 1|3I3|12|6|0|106002|1|0|jason|\\z\\z|0|0|0|��η�ļž�|0 )");
			connection->send_raw(R"(C 2|1tq|10|5|4|14088|1|0|����ҽʦ|\\z\\z|0|0|0||0        37|1ty|10|17|4|14088|1|0|ķ��ҽʦ|\\z\\z|0|0|0||0      2|1ti|12|5|4|14090|1|0|ʵϰҩ��ʦ����|\\z\\z|0|0|0||0    29|1xH|16|9|6|14151|1|0|ʵϰ������|\\z\\z|0|0|0||0)");
			connection->send_raw(R"(BT 5Co 0 )");
			connection->send_raw(R"(POS 0 )");
			connection->send_raw(R"(AL 1 0|0|0|0|0|0|0|0|0|0| )");
			connection->send_raw(R"(IP 127.0.0.1 )");
			connection->send_raw(R"(MAC Y O )");
			connection->send_raw(R"(EF 0 0  )");
			connection->send_raw(R"(TK -1 P|��л��������ħ����wow335.taobao.com 4 0 )");
			connection->send_raw(R"(TK -1 P|[�汾����]GMSV\SAvaritia\SFeb\S\S1\S2014\S����� 4 0 )");
			connection->send_raw(R"(TK -1 P|������˽����о�ʹ�ã�����������ҵ��;�� 4 0 )");
			connection->send_raw(R"(TK -1 P|��Ŀ��ҳ\S&\S������̳��http://www.cgdev.me/ 4 0 )");
			connection->send_raw(R"(STK GA\SLua�������������� )");
			connection->send_raw(R"(STK [����ħ������]����\S/help\Sָ��鿴��ǰ����LuaTalkָ�� )");
			//connection->send_raw(R"()");
		}

		struct opcode_entry
		{
			enum xg_opcode opcode;
			const char* opstring;
			uint32 opstring_size;
			void (*handler)(xg_packet* packet);
		};

		enum xg_opcode : uint16
		{
			XG_FC,
			XG_ECHO,
			XG_CLIENT_LOGIN,
			XG_CHAR_LIST,
			XG_CHAR_LOGIN,
			XG_OPCODE_COUNT
		};

#define add_opcode_entry(opcode, opstring, handler) \
		{ opcode, opstring, sizeof(opstring) / sizeof(char) - 1, handler }

		opcode_entry xg_opcode_table[XG_OPCODE_COUNT] =
		{
			add_opcode_entry(XG_FC,						"FC",					&handle_fc),
			add_opcode_entry(XG_ECHO,					"Echo",					&handle_echo),
			add_opcode_entry(XG_CLIENT_LOGIN,			"ClientLogin",			&handle_client_login),
			add_opcode_entry(XG_CHAR_LIST,				"CharList",				&handle_char_list),
			add_opcode_entry(XG_CHAR_LOGIN,				"CharLogin",			&handle_char_login),
		};

		template<typename T, size_t N>
		int mystrncmp(const T* a, const T(&b)[N])
		{
			return _tcsnccmp(a, b, N - 1);
		}

		void xg_dispatch_packet(core::packet&& packet)
		{
			xg_packet xg_packet(std::move(packet));

			for (uint32 i = 0; i < XG_OPCODE_COUNT; i++)
			{
				auto opstring = xg_opcode_table[i].opstring;
				auto opstring_size = xg_opcode_table[i].opstring_size;
				if (!strncmp((char*)packet.data, opstring, opstring_size))
				{
					auto handler = xg_opcode_table[i].handler;
					handler(&xg_packet);
					return;
				}
			}

			printf("Unhandled packet:%s\n", xg_packet.data);
		}
	}
}
