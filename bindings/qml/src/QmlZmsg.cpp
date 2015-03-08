/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/

#include "QmlZmsg.h"


///
//  Return size of message, i.e. number of frames (0 or more).
size_t QmlZmsg::size () {
    return zmsg_size (self);
};

///
//  Return total size of all frames in message.
size_t QmlZmsg::contentSize () {
    return zmsg_content_size (self);
};

///
//  Push frame to the front of the message, i.e. before all other frames.  
//  Message takes ownership of frame, will destroy it when message is sent.
//  Returns 0 on success, -1 on error. Deprecates zmsg_push, which did not 
//  nullify the caller's frame reference.                                  
int QmlZmsg::prepend (QmlZframe *frameP) {
    return zmsg_prepend (self, &frameP->self);
};

///
//  Add frame to the end of the message, i.e. after all other frames.      
//  Message takes ownership of frame, will destroy it when message is sent.
//  Returns 0 on success. Deprecates zmsg_add, which did not nullify the   
//  caller's frame reference.                                              
int QmlZmsg::append (QmlZframe *frameP) {
    return zmsg_append (self, &frameP->self);
};

///
//  Remove first frame from message, if any. Returns frame, or NULL. Caller
//  now owns frame and must destroy it when finished with it.              
QmlZframe *QmlZmsg::pop () {
    QmlZframe *retQ_ = new QmlZframe ();
    retQ_->self = zmsg_pop (self);
    return retQ_;
};

///
//  Push block of memory to front of message, as a new frame.
//  Returns 0 on success, -1 on error.                       
int QmlZmsg::pushmem (const void *src, size_t size) {
    return zmsg_pushmem (self, src, size);
};

///
//  Add block of memory to the end of the message, as a new frame.
//  Returns 0 on success, -1 on error.                            
int QmlZmsg::addmem (const void *src, size_t size) {
    return zmsg_addmem (self, src, size);
};

///
//  Push string as new frame to front of message.
//  Returns 0 on success, -1 on error.           
int QmlZmsg::pushstr (const QString &string) {
    return zmsg_pushstr (self, string.toUtf8().data());
};

///
//  Push string as new frame to end of message.
//  Returns 0 on success, -1 on error.         
int QmlZmsg::addstr (const QString &string) {
    return zmsg_addstr (self, string.toUtf8().data());
};

///
//  Push formatted string as new frame to front of message.
//  Returns 0 on success, -1 on error.                     
int QmlZmsg::pushstrf (const QString &format) {
    return zmsg_pushstrf (self, "%s", format.toUtf8().data());
};

///
//  Push formatted string as new frame to end of message.
//  Returns 0 on success, -1 on error.                   
int QmlZmsg::addstrf (const QString &format) {
    return zmsg_addstrf (self, "%s", format.toUtf8().data());
};

///
//  Pop frame off front of message, return as fresh string. If there were
//  no more frames in the message, returns NULL.                         
QString QmlZmsg::popstr () {
    char *retStr_ = zmsg_popstr (self);
    QString retQStr_ = QString (retStr_);
    free (retStr_);
    return retQStr_;
};

///
//  Push encoded message as a new frame. Message takes ownership of    
//  submessage, so the original is destroyed in this call. Returns 0 on
//  success, -1 on error.                                              
int QmlZmsg::addmsg (QmlZmsg *msgP) {
    return zmsg_addmsg (self, &msgP->self);
};

///
//  Remove first submessage from message, if any. Returns zmsg_t, or NULL if
//  decoding was not succesfull. Caller now owns message and must destroy it
//  when finished with it.                                                  
QmlZmsg *QmlZmsg::popmsg () {
    QmlZmsg *retQ_ = new QmlZmsg ();
    retQ_->self = zmsg_popmsg (self);
    return retQ_;
};

///
//  Remove specified frame from list, if present. Does not destroy frame.
void QmlZmsg::remove (QmlZframe *frame) {
    zmsg_remove (self, frame->self);
};

///
//  Set cursor to first frame in message. Returns frame, or NULL, if the 
//  message is empty. Use this to navigate the frames as a list.         
QmlZframe *QmlZmsg::first () {
    QmlZframe *retQ_ = new QmlZframe ();
    retQ_->self = zmsg_first (self);
    return retQ_;
};

///
//  Return the next frame. If there are no more frames, returns NULL. To move
//  to the first frame call zmsg_first(). Advances the cursor.               
QmlZframe *QmlZmsg::next () {
    QmlZframe *retQ_ = new QmlZframe ();
    retQ_->self = zmsg_next (self);
    return retQ_;
};

///
//  Return the last frame. If there are no frames, returns NULL.
QmlZframe *QmlZmsg::last () {
    QmlZframe *retQ_ = new QmlZframe ();
    retQ_->self = zmsg_last (self);
    return retQ_;
};

///
//  Save message to an open file, return 0 if OK, else -1. The message is  
//  saved as a series of frames, each with length and data. Note that the  
//  file is NOT guaranteed to be portable between operating systems, not   
//  versions of CZMQ. The file format is at present undocumented and liable
//  to arbitrary change.                                                   
int QmlZmsg::save (FILE *file) {
    return zmsg_save (self, file);
};

///
//  Serialize multipart message to a single buffer. Use this method to send  
//  structured messages across transports that do not support multipart data.
//  Allocates and returns a new buffer containing the serialized message.    
//  To decode a serialized message buffer, use zmsg_decode ().               
size_t QmlZmsg::encode (byte **buffer) {
    return zmsg_encode (self, buffer);
};

///
//  Create copy of message, as new message object. Returns a fresh zmsg_t
//  object. If message is null, or memory was exhausted, returns null.   
QmlZmsg *QmlZmsg::dup () {
    QmlZmsg *retQ_ = new QmlZmsg ();
    retQ_->self = zmsg_dup (self);
    return retQ_;
};

///
//  Send message to zsys log sink (may be stdout, or system facility as
//  configured by zsys_set_logstream).                                 
void QmlZmsg::print () {
    zmsg_print (self);
};

///
//  Return true if the two messages have the same number of frames and each  
//  frame in the first message is identical to the corresponding frame in the
//  other message. As with zframe_eq, return false if either message is NULL.
bool QmlZmsg::eq (QmlZmsg *other) {
    return zmsg_eq (self, other->self);
};

///
//  Return signal value, 0 or greater, if message is a signal, -1 if not.
int QmlZmsg::signal () {
    return zmsg_signal (self);
};


QObject* QmlZmsg::qmlAttachedProperties(QObject* object) {
    return new QmlZmsgAttached(object);
}


///
//  Receive message from socket, returns zmsg_t object or NULL if the recv   
//  was interrupted. Does a blocking recv. If you want to not block then use 
//  the zloop class or zmsg_recv_nowait or zmq_poll to check for socket input
//  before receiving.                                                        
QmlZmsg *QmlZmsgAttached::recv (void *source) {
    QmlZmsg *retQ_ = new QmlZmsg ();
    retQ_->self = zmsg_recv (source);
    return retQ_;
};

///
//  Send message to destination socket, and destroy the message after sending
//  it successfully. If the message has no frames, sends nothing but destroys
//  the message anyhow. Nullifies the caller's reference to the message (as  
//  it is a destructor).                                                     
int QmlZmsgAttached::send (QmlZmsg *selfP, void *dest) {
    return zmsg_send (&selfP->self, dest);
};

///
//  Load/append an open file into message, create new message if 
//  null message provided. Returns NULL if the message could not 
//  be loaded.                                                   
QmlZmsg *QmlZmsgAttached::load (QmlZmsg *self, FILE *file) {
    QmlZmsg *retQ_ = new QmlZmsg ();
    retQ_->self = zmsg_load (self->self, file);
    return retQ_;
};

///
//  Decodes a serialized message buffer created by zmsg_encode () and returns
//  a new zmsg_t object. Returns NULL if the buffer was badly formatted or   
//  there was insufficient memory to work.                                   
QmlZmsg *QmlZmsgAttached::decode (const byte *buffer, size_t bufferSize) {
    QmlZmsg *retQ_ = new QmlZmsg ();
    retQ_->self = zmsg_decode (buffer, bufferSize);
    return retQ_;
};

///
//  Generate a signal message encoding the given status. A signal is a short
//  message carrying a 1-byte success/failure code (by convention, 0 means  
//  OK). Signals are encoded to be distinguishable from "normal" messages.  
QmlZmsg *QmlZmsgAttached::newSignal (byte status) {
    QmlZmsg *retQ_ = new QmlZmsg ();
    retQ_->self = zmsg_new_signal (status);
    return retQ_;
};

///
//  Probe the supplied object, and report if it looks like a zmsg_t.
bool QmlZmsgAttached::is (void *self) {
    return zmsg_is (self);
};

///
//  Self test of this class
void QmlZmsgAttached::test (bool verbose) {
    zmsg_test (verbose);
};

///
//  Create a new empty message object
QmlZmsg *QmlZmsgAttached::construct () {
    QmlZmsg *qmlSelf = new QmlZmsg ();
    qmlSelf->self = zmsg_new ();
    return qmlSelf;
};

///
//  Destroy a message object and all frames it contains
void QmlZmsgAttached::destruct (QmlZmsg *qmlSelf) {
    zmsg_destroy (&qmlSelf->self);
};

/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
