#include "stdafx.h"
#include "config.h"

socket_t tcp_socket = 0;
LPFDWATCH main_fdw = nullptr;

bool start(int argc, char **argv);
int idle();

bool start(int argc, char **argv)
{
	signal_timer_disable();
	main_fdw = fdwatch_new(4096);

	if ((tcp_socket = socket_tcp_bind(g_szPublicIP, mother_port)) == INVALID_SOCKET)
	{
		perror("socket_tcp_bind: tcp_socket");
		return false;
	}

	fdwatch_add_fd(main_fdw, tcp_socket, nullptr, FDW_READ, false);

	signal_timer_enable(30);

    return true;
}

int main(int argc, char **argv)
{
	if (!start(argc, argv)) {
		return 0;
	}

	while (idle());

    return 0;
}

int idle()
{

	// int passed_pulses;

	// if (!(passed_pulses = thecore_idle()))
	// 	return 0;

	// assert(passed_pulses > 0);

	// DWORD t;

	// while (passed_pulses--) {
	// 	heartbeat(thecore_heart, ++thecore_heart->pulse);

	// 	// To reduce the possibility of abort() in checkpointing
	// 	thecore_tick();
	// }

	if (!io_loop(main_fdw))
        return 0;

	// log_rotate();


	return 1;
}

int io_loop(LPFDWATCH fdw)
{
	int		num_events, event_idx;

	if ((num_events = fdwatch(fdw, 0)) < 0)
		return 0;

	for (event_idx = 0; event_idx < num_events; ++event_idx)
	{
		int iRet = fdwatch_check_event(fdw, d->GetSocket(), event_idx);

		switch (iRet)
		{
		case FDW_READ:
			if (db_clientdesc == d)
			{
				int size = d->ProcessInput();

				if (size)
					sys_log(1, "DB_BYTES_READ: %d", size);

				if (size < 0)
				{
					d->SetPhase(PHASE_CLOSE);
				}
			}
			else if (d->ProcessInput() < 0)
			{
				d->SetPhase(PHASE_CLOSE);
			}
			break;

		case FDW_WRITE:
			if (db_clientdesc == d)
			{
				int buf_size = buffer_size(d->GetOutputBuffer());
				int sock_buf_size = fdwatch_get_buffer_size(fdw, d->GetSocket());

				int ret = d->ProcessOutput();

				if (ret < 0)
				{
					d->SetPhase(PHASE_CLOSE);
				}

				if (buf_size)
					sys_log(1, "DB_BYTES_WRITE: size %d sock_buf %d ret %d", buf_size, sock_buf_size, ret);
			}
			else if (d->ProcessOutput() < 0)
			{
				d->SetPhase(PHASE_CLOSE);
			}
			break;

		case FDW_EOF:
		{
			d->SetPhase(PHASE_CLOSE);
		}
		break;

		default:
			sys_err("fdwatch_check_event returned unknown %d", iRet);
			d->SetPhase(PHASE_CLOSE);
			break;
		}
	}

	return 1;
}