/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/

#ifndef QML_ZMSG_H
#define QML_ZMSG_H

#include <QtQml>

#include <czmq.h>
#include "qml_czmq_plugin.h"


class QmlZmsg : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isNULL READ isNULL)
    
public:
    zmsg_t *self;
    
    QmlZmsg() { self = NULL; }
    bool isNULL() { return self == NULL; }
    
    static QObject* qmlAttachedProperties(QObject* object); // defined in QmlZmsg.cpp
    
public slots:
    //  Return size of message, i.e. number of frames (0 or more).
    size_t size ();

    //  Return total size of all frames in message.
    size_t contentSize ();

    //  Push frame to the front of the message, i.e. before all other frames.  
    //  Message takes ownership of frame, will destroy it when message is sent.
    //  Returns 0 on success, -1 on error. Deprecates zmsg_push, which did not 
    //  nullify the caller's frame reference.                                  
    int prepend (QmlZframe *frameP);

    //  Add frame to the end of the message, i.e. after all other frames.      
    //  Message takes ownership of frame, will destroy it when message is sent.
    //  Returns 0 on success. Deprecates zmsg_add, which did not nullify the   
    //  caller's frame reference.                                              
    int append (QmlZframe *frameP);

    //  Remove first frame from message, if any. Returns frame, or NULL. Caller
    //  now owns frame and must destroy it when finished with it.              
    QmlZframe *pop ();

    //  Push block of memory to front of message, as a new frame.
    //  Returns 0 on success, -1 on error.                       
    int pushmem (const void *src, size_t size);

    //  Add block of memory to the end of the message, as a new frame.
    //  Returns 0 on success, -1 on error.                            
    int addmem (const void *src, size_t size);

    //  Push string as new frame to front of message.
    //  Returns 0 on success, -1 on error.           
    int pushstr (const QString &string);

    //  Push string as new frame to end of message.
    //  Returns 0 on success, -1 on error.         
    int addstr (const QString &string);

    //  Push formatted string as new frame to front of message.
    //  Returns 0 on success, -1 on error.                     
    int pushstrf (const QString &format);

    //  Push formatted string as new frame to end of message.
    //  Returns 0 on success, -1 on error.                   
    int addstrf (const QString &format);

    //  Pop frame off front of message, return as fresh string. If there were
    //  no more frames in the message, returns NULL.                         
    QString popstr ();

    //  Push encoded message as a new frame. Message takes ownership of    
    //  submessage, so the original is destroyed in this call. Returns 0 on
    //  success, -1 on error.                                              
    int addmsg (QmlZmsg *msgP);

    //  Remove first submessage from message, if any. Returns zmsg_t, or NULL if
    //  decoding was not succesfull. Caller now owns message and must destroy it
    //  when finished with it.                                                  
    QmlZmsg *popmsg ();

    //  Remove specified frame from list, if present. Does not destroy frame.
    void remove (QmlZframe *frame);

    //  Set cursor to first frame in message. Returns frame, or NULL, if the 
    //  message is empty. Use this to navigate the frames as a list.         
    QmlZframe *first ();

    //  Return the next frame. If there are no more frames, returns NULL. To move
    //  to the first frame call zmsg_first(). Advances the cursor.               
    QmlZframe *next ();

    //  Return the last frame. If there are no frames, returns NULL.
    QmlZframe *last ();

    //  Save message to an open file, return 0 if OK, else -1. The message is  
    //  saved as a series of frames, each with length and data. Note that the  
    //  file is NOT guaranteed to be portable between operating systems, not   
    //  versions of CZMQ. The file format is at present undocumented and liable
    //  to arbitrary change.                                                   
    int save (FILE *file);

    //  Serialize multipart message to a single buffer. Use this method to send  
    //  structured messages across transports that do not support multipart data.
    //  Allocates and returns a new buffer containing the serialized message.    
    //  To decode a serialized message buffer, use zmsg_decode ().               
    size_t encode (byte **buffer);

    //  Create copy of message, as new message object. Returns a fresh zmsg_t
    //  object. If message is null, or memory was exhausted, returns null.   
    QmlZmsg *dup ();

    //  Send message to zsys log sink (may be stdout, or system facility as
    //  configured by zsys_set_logstream).                                 
    void print ();

    //  Return true if the two messages have the same number of frames and each  
    //  frame in the first message is identical to the corresponding frame in the
    //  other message. As with zframe_eq, return false if either message is NULL.
    bool eq (QmlZmsg *other);

    //  Return signal value, 0 or greater, if message is a signal, -1 if not.
    int signal ();
};

class QmlZmsgAttached : public QObject
{
    Q_OBJECT
    QObject* m_attached;
    
public:
    QmlZmsgAttached (QObject* attached) {
        Q_UNUSED (attached);
    };
    
public slots:
    //  Receive message from socket, returns zmsg_t object or NULL if the recv   
    //  was interrupted. Does a blocking recv. If you want to not block then use 
    //  the zloop class or zmsg_recv_nowait or zmq_poll to check for socket input
    //  before receiving.                                                        
    QmlZmsg *recv (void *source);

    //  Send message to destination socket, and destroy the message after sending
    //  it successfully. If the message has no frames, sends nothing but destroys
    //  the message anyhow. Nullifies the caller's reference to the message (as  
    //  it is a destructor).                                                     
    int send (QmlZmsg *selfP, void *dest);

    //  Load/append an open file into message, create new message if 
    //  null message provided. Returns NULL if the message could not 
    //  be loaded.                                                   
    QmlZmsg *load (QmlZmsg *self, FILE *file);

    //  Decodes a serialized message buffer created by zmsg_encode () and returns
    //  a new zmsg_t object. Returns NULL if the buffer was badly formatted or   
    //  there was insufficient memory to work.                                   
    QmlZmsg *decode (const byte *buffer, size_t bufferSize);

    //  Generate a signal message encoding the given status. A signal is a short
    //  message carrying a 1-byte success/failure code (by convention, 0 means  
    //  OK). Signals are encoded to be distinguishable from "normal" messages.  
    QmlZmsg *newSignal (byte status);

    //  Probe the supplied object, and report if it looks like a zmsg_t.
    bool is (void *self);

    //  Self test of this class
    void test (bool verbose);

    //  Create a new empty message object
    QmlZmsg *construct ();

    //  Destroy a message object and all frames it contains
    void destruct (QmlZmsg *qmlSelf);
};


QML_DECLARE_TYPEINFO(QmlZmsg, QML_HAS_ATTACHED_PROPERTIES)

#endif
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
