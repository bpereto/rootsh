
enum {
        TYPE_UDP = (1 << 1),
        TYPE_TCP = (1 << 2),
        ALL_TYPES = TYPE_UDP | TYPE_TCP
};

enum {
        AF_UNIX_ERRORS_OFF = 0,
        AF_UNIX_ERRORS_ON,
        AF_UNIX_ERRORS_AUTO
};

struct logger_ctl {
    int fd;
    int pri;
    pid_t pid;          /* zero when unwanted */
    char *hdr;          /* the syslog header (based on protocol) */
    char *tag;
    char *msgid;
    char *unix_socket;      
    char *server;
    char *port;
    int socket_type;
    size_t max_message_size;
    void (*syslogfp)(struct logger_ctl *ctl);
    unsigned int
            unix_socket_errors:1,   /* whether to report or not errors */
            noact:1,        /* do not write to sockets */
            prio_prefix:1,      /* read priority from intput */
            stderr_printout:1,  /* output message to stderr */
            rfc5424_time:1,     /* include time stamp */
            rfc5424_tq:1,       /* include time quality markup */
            rfc5424_host:1,     /* include hostname */
            skip_empty_lines:1, /* do not send empty lines when processing files */
            octet_count:1;      /* use RFC6587 octet counting */
};

extern struct logger_ctl ctl;

#define UNUSED(x) (void)(x)
