/*
 *	HT Editor
 *	terminal.h
 *
 *	Copyright (C) 2002 Stefan Weyergraf (stefan@weyergraf.de)
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License version 2 as
 *	published by the Free Software Foundation.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program; if not, write to the Free Software
 *	Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef __TERMINAL_H__
#define __TERMINAL_H__

#include "textedit.h"

/*
 *	CLASS Terminal
 */

class Terminal: public ht_ltextfile {
private:
	ht_streamfile *in, *out, *err;
	int sys_ipc_handle;

			bool append(ht_streamfile *file);
public:
			void init(ht_streamfile *in, ht_streamfile *out, ht_streamfile *err, int sys_ipc_handle);
	virtual	void done();
/* oerwritten */	
	virtual	UINT write(const void *buf, UINT size);
/* new */
			bool connected();
			bool update();
};

/*
 *	CLASS TerminalViewer
 */

class TerminalViewer: public ht_text_viewer {
private:
	Terminal	*term;
	
	        void do_update();
		void get_pindicator_str(char *buf);
public:
	        void init(bounds *b, Terminal *term, bool own_term);
	virtual	void done();
/* overwritten */
	virtual	void handlemsg(htmsg *msg);
	virtual	bool idle();
};

#endif /* __TERMINAL_H__ */

